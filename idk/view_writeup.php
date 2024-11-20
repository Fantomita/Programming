<?php
session_start();

if (!isset($_GET['id'])) {
    echo "Problem ID not provided.";
    exit;
}

$problemId = $_GET['id'];

try {
    // Connect to the SQLite database
    $pdo = new PDO('sqlite:/var/www/db/problems.db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Fetch the write-up from the database using the provided ID
    $stmt = $pdo->prepare("SELECT * FROM write_ups WHERE id = ?");
    $stmt->execute([$problemId]);
    $writeup = $stmt->fetch(PDO::FETCH_ASSOC);

    if (!$writeup) {
        echo "Problem not found.";
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
    <title>Solution: <?= htmlspecialchars($writeup['title']) ?></title>
    <link rel="stylesheet" href="../styles/main.css">
    <!-- highlight.js CSS -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/styles/vs-dark.min.css">
    <!-- highlight.js JavaScript -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/highlight.min.js"></script>
    <script>hljs.highlightAll();</script>
</head>
<body>
    <header>
        <h1>Solution: <?= htmlspecialchars($writeup['title']) ?></h1>
    </header>
    <nav>
        <a href="../index.php">Home</a>
        <a href="../problems.php">Problems</a>
        <a href="../about.php">About</a>
        
        <?php
        if (isset($_SESSION['user'])) {
            echo '<a href="/login/logout.php">Logout</a>';
        } else {
            echo '<a href="/login/login.php">Login</a>';
        }
        ?>
    </nav>
    <div class="container">
        <h2>Problem Link</h2>
        <a href="<?= htmlspecialchars($writeup['link']) ?>" target="_blank"><?= htmlspecialchars($writeup['link']) ?></a>
        
        <h2>Problem Description</h2>
        <p><?= nl2br(htmlspecialchars($writeup['description'])) ?></p>
        
        <h2>Solution Code</h2>
        <pre><code class="language-<?= htmlspecialchars($writeup['language']) ?>">
<?php
    // Display the solution code directly
    echo htmlspecialchars($writeup['code_text']);
?>
        </code></pre>
    </div>
    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
