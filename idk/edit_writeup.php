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
    <!-- Highlight.js CSS -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/styles/vs-dark.min.css">

    <!-- SimpleMDE JS -->
    <script src="https://cdn.jsdelivr.net/simplemde/latest/simplemde.min.js"></script>
    <!-- Highlight.js JS -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/highlight.min.js"></script>

    <style>
        /* Markdown Preview Styles for SimpleMDE */
        .editor-preview,
        .editor-preview-side {
            white-space: normal; /* Normal white-space for better wrapping */
            overflow-x: auto;
            font-family: 'Consolas', 'Monaco', 'Courier New', monospace;
            padding: 15px; /* Slightly reduced padding */
            background-color: #1E1E1E;
            border-radius: 5px;
            color: #ffffff;
            line-height: 1.4; /* Adjusted line height for readability */
        }

        .editor-preview p,
        .editor-preview-side p {
            margin: 0.8em 0; /* Slightly reduced margin */
        }

        .editor-preview pre,
        .editor-preview-side pre {
            background-color: #2d2d2d;
            padding: 10px; /* Reduced padding */
            margin: 0.8em 0; /* Reduced margin */
            border-radius: 4px;
            white-space: pre;
        }

        .editor-preview code,
        .editor-preview-side code {
            background-color: #2d2d2d; /* Highlight inline code */
            padding: 2px 4px;
            border-radius: 3px;
            color: #dcdcaa;
            font-family: 'Consolas', 'Monaco', 'Courier New', monospace;
            font-size: 90%; /* Slightly smaller for inline */
        }

        .editor-preview h1,
        .editor-preview-side h1,
        .editor-preview h2,
        .editor-preview-side h2,
        .editor-preview h3,
        .editor-preview-side h3,
        .editor-preview h4,
        .editor-preview-side h4,
        .editor-preview h5,
        .editor-preview-side h5,
        .editor-preview h6,
        .editor-preview-side h6 {
            margin-top: 1.2em;
            margin-bottom: 0.4em; /* Compact spacing */
            font-weight: bold;
        }

        .editor-preview blockquote,
        .editor-preview-side blockquote {
            border-left: 3px solid #444;
            margin: 1em 0;
            padding-left: 1em;
            color: #aaa;
            font-style: italic;
        }

        .editor-preview ul,
        .editor-preview-side ul,
        .editor-preview ol,
        .editor-preview-side ol {
            padding-left: 1.5em; /* Reduced indentation */
            margin: 0.8em 0; /* Compact spacing */
        }

        .editor-preview li,
        .editor-preview-side li {
            margin: 0.4em 0; /* Compact spacing for list items */
        }

        .editor-preview table,
        .editor-preview-side table {
            border-collapse: collapse;
            margin: 1em 0;
            width: 100%;
            border: 1px solid #444; /* Added border for tables */
        }

        .editor-preview th,
        .editor-preview-side th,
        .editor-preview td,
        .editor-preview-side td {
            padding: 8px;
            text-align: left;
            border: 1px solid #444;
        }

        .editor-preview th,
        .editor-preview-side th {
            background-color: #2d2d2d;
        }

        .editor-preview hr,
        .editor-preview-side hr {
            border: none;
            border-top: 1px solid #444;
            margin: 1.5em 0; /* Reduced margin for compactness */
        }
    </style>
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
            <textarea name="description" id="description" required><?= htmlspecialchars($writeup['description']) ?></textarea>
            <br>

            <label for="code_text">Solution Code:</label>
            <textarea name="code_text" id="code_text"><?= htmlspecialchars($writeup['code_text']) ?></textarea>
            <br>

            <button type="submit">Save Changes</button>
        </form>
    </div>

    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>

    <script>
        // Initialize SimpleMDE for Markdown editing
        const simplemde = new SimpleMDE({
            element: document.getElementById("description"),
            spellChecker: false,
        });

        // Highlight code block for Solution Code
        document.addEventListener("DOMContentLoaded", function () {
            hljs.highlightAll();
        });
    </script>
</body>
</html>
