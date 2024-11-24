<?php
session_start();

if (!isset($_SESSION['user']) || $_SESSION['is_admin'] != 1) {
    header('Location: ../index.php'); // Redirect if not logged in as admin
    exit;
}

try {
    // Connect to SQLite database
    $pdo = new PDO('sqlite:/var/www/db/problems.db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Fetch existing categories
    $categories = $pdo->query("SELECT id, name FROM categories")->fetchAll(PDO::FETCH_ASSOC);
} catch (PDOException $e) {
    die("Database error: " . $e->getMessage());
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // Get form input
    $title = $_POST['title'];
    $link = $_POST['link'];
    $description = $_POST['description'];
    $language = $_POST['language'];
    $codeText = $_POST['code_text'] ?? '';
    $selectedCategory = $_POST['category'];
    $newCategoryName = $_POST['new_category_name'] ?? null;

    // Handle file upload
    $codeFilePath = '';

    if (isset($_FILES['code_file']) && $_FILES['code_file']['error'] == UPLOAD_ERR_OK) {
        $uploadedFile = $_FILES['code_file'];
        $extension = pathinfo($uploadedFile['name'], PATHINFO_EXTENSION);
        $uniqueHash = bin2hex(random_bytes(16));
        $newFileName = '/var/www/code/' . $uniqueHash . '.' . $extension;
    
        if (move_uploaded_file($uploadedFile['tmp_name'], $newFileName)) {
            $codeFilePath = $newFileName;
        }
    }

    try {
        // Add new category if "New Category" is selected
        if ($selectedCategory === 'new' && $newCategoryName) {
            $stmt = $pdo->prepare("INSERT INTO categories (name) VALUES (?)");
            $stmt->execute([$newCategoryName]);
            $selectedCategory = $pdo->lastInsertId();
        }

        // Insert new write-up
        $stmt = $pdo->prepare("INSERT INTO write_ups (title, link, description, code_file, code_text, language, category_id) 
                              VALUES (?, ?, ?, ?, ?, ?, ?)");
        $stmt->execute([$title, $link, $description, $codeFilePath, $codeText, $language, $selectedCategory]);

        // Redirect after successful insertion
        header('Location: problems.php');
        exit;
    } catch (PDOException $e) {
        echo "Error: " . $e->getMessage();
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add New Write-Up</title>
    <link rel="stylesheet" href="../styles/main.css">
    <!-- SimpleMDE CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/simplemde/latest/simplemde.min.css">
    <!-- SimpleMDE JS -->
    <script src="https://cdn.jsdelivr.net/simplemde/latest/simplemde.min.js"></script>
    <script>
        function toggleNewCategoryInput() {
            const categorySelect = document.getElementById('category');
            const newCategoryInput = document.getElementById('new-category-name');

            if (categorySelect.value === 'new') {
                newCategoryInput.style.display = 'block';
                newCategoryInput.required = true;
            } else {
                newCategoryInput.style.display = 'none';
                newCategoryInput.required = false;
            }
        }
    </script>
</head>
<body>
    <header>
        <h1>Add New Write-Up</h1>
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
        <h2>Enter Write-Up Details</h2>
        <form method="POST" enctype="multipart/form-data">
            <label for="title">Write-Up Title:</label>
            <input type="text" name="title" id="title" required><br>

            <label for="link">Problem Link (URL to problem):</label>
            <input type="text" name="link" id="link" required><br>

            <label for="description">Detailed Description (Markdown Supported):</label>
            <textarea name="description" id="description" style="display: block;"></textarea><br>

            <label for="code_file">Solution File (optional):</label>
            <input type="file" name="code_file" id="code_file"><br>

            <label for="code_text">Solution Code (or enter code here):</label>
            <textarea name="code_text" id="code_text"></textarea><br>

            <label for="language">Programming Language:</label>
            <select name="language" id="language">
                <option value="python">Python</option>
                <option value="cpp">C++</option>
                <option value="java">Java</option>
                <option value="javascript">JavaScript</option>
                <option value="php">PHP</option>
            </select><br>

            <label for="category">Category:</label>
            <select name="category" id="category" onchange="toggleNewCategoryInput()" required>
                <option value="">Select a Category</option>
                <?php foreach ($categories as $category): ?>
                    <option value="<?= $category['id'] ?>"><?= htmlspecialchars($category['name']) ?></option>
                <?php endforeach; ?>
                <option value="new">New Category</option>
            </select><br>

            <div id="new-category-name" style="display: none;">
                <label for="new_category_name">New Category Name:</label>
                <input type="text" name="new_category_name" id="new_category_name" placeholder="Enter new category name"><br>
            </div>

            <button type="submit">Submit Write-Up</button>
        </form>
    </div>

    <script>
        document.addEventListener('DOMContentLoaded', function() {
            // Make sure the textarea exists and is visible before initializing SimpleMDE
            const descriptionTextarea = document.getElementById('description');
            if (descriptionTextarea) {
                // Initialize SimpleMDE with basic configuration
                const simplemde = new SimpleMDE({
                    element: descriptionTextarea,
                    forceSync: true // Force sync with original textarea on change
                });
            }
        });
    </script>

    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>