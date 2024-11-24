<?php
session_start();

// Check if the user is an admin
if (!isset($_SESSION['user']) || $_SESSION['is_admin'] != 1) {
    header('Location: ../index.php'); // Redirect if not logged in as admin
    exit;
}

if (!isset($_GET['id'])) {
    echo "Write-Up ID not provided.";
    exit;
}

$problemId = $_GET['id'];

try {
    // Connect to SQLite database
    $pdo = new PDO('sqlite:/var/www/db/problems.db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Fetch the write-up details
    $stmt = $pdo->prepare("SELECT * FROM write_ups WHERE id = ?");
    $stmt->execute([$problemId]);
    $writeup = $stmt->fetch(PDO::FETCH_ASSOC);

    if (!$writeup) {
        echo "Write-Up not found.";
        exit;
    }

    // Handle form submission
    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $title = $_POST['title'];
        $link = $_POST['link'];
        $description = $_POST['description']; // Markdown content from textarea
        $codeText = $_POST['code_text']; // Solution code entered directly in text box

        // Update the write-up in the database
        $stmt = $pdo->prepare("UPDATE write_ups SET title = ?, link = ?, description = ?, code_text = ? WHERE id = ?");
        $stmt->execute([$title, $link, $description, $codeText, $problemId]);

        // Redirect to the view page after saving
        header('Location: view_writeup.php?id=' . $problemId);
        exit;
    }
} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Edit Write-Up</title>
    <link rel="stylesheet" href="../styles/main.css">

    <!-- SimpleMDE CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/simplemde/latest/simplemde.min.css">
    <!-- SimpleMDE JS -->
    <script src="https://cdn.jsdelivr.net/simplemde/latest/simplemde.min.js"></script>
</head>
<body>
    <header>
        <h1>Edit Write-Up</h1>
    </header>
    <nav>
        <a href="../index.php">Home</a>
        <a href="../problems.php">Problems</a>
        <a href="../about.php">About</a>
        <a href="/login/logout.php">Logout</a>
    </nav>
    <div class="container">
        <form method="POST">
            <label for="title">Title:</label>
            <input type="text" name="title" id="title" value="<?= htmlspecialchars($writeup['title']) ?>" required><br>

            <label for="link">Problem Link:</label>
            <input type="text" name="link" id="link" value="<?= htmlspecialchars($writeup['link']) ?>" required><br>

            <label for="description">Description (Markdown Supported):</label>
            <!-- SimpleMDE Markdown Editor -->
            <textarea name="description" id="description" required><?= htmlspecialchars($writeup['description']) ?></textarea><br>
            <script>
                const simplemde = new SimpleMDE({ element: document.getElementById("description") });
            </script>

            <label for="code_text">Solution Code:</label>
            <textarea name="code_text" id="code_text"><?= htmlspecialchars($writeup['code_text']) ?></textarea><br>

            <button type="submit">Save Changes</button>
        </form>
    </div>

    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
