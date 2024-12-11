<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

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

    // Check if there's a file and read it
    if (!empty($writeup['code_file']) && file_exists($writeup['code_file'])) {
        $fileContent = file_get_contents($writeup['code_file']);
    } else {
        $fileContent = '';
    }

    // Load Parsedown
    require_once '/var/www/libs/Parsedown.php';
    $parsedown = new Parsedown();

    // Configure Parsedown to preserve line breaks
    $parsedown->setBreaksEnabled(true);

    // Parse the description as Markdown
    $descriptionHtml = $parsedown->text($writeup['description']);

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
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/styles/vs-dark.min.css">

    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/highlight.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/languages/cpp.min.js"></script>

    <script>
        document.addEventListener("DOMContentLoaded", function () {
            // Initialize highlight.js
            hljs.configure({
                languages: ['cpp', 'python', 'java', 'javascript']
            });
            hljs.highlightAll();

            // Add "Copy Code" functionality
            document.querySelectorAll('.copy-button').forEach(button => {
                button.addEventListener('click', function () {
                    const codeBlock = this.nextElementSibling;
                    const codeText = codeBlock.querySelector('code').innerText;

                    navigator.clipboard.writeText(codeText)
                        .then(() => {
                            button.textContent = "Copied!";
                            setTimeout(() => (button.textContent = "Copy Code"), 2000);
                        })
                        .catch(err => console.error("Failed to copy code:", err));
                });
            });
        });
    </script>
    <style>
        /* General Layout Styles */
        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 20px;
        }

        /* Code Container Styles */
        .code-container {
            position: relative;
            margin: 20px 0;
        }

        .copy-button {
            position: absolute;
            top: 10px;
            right: 10px;
            background-color: #007BFF;
            color: white;
            border: none;
            padding: 5px 10px;
            border-radius: 5px;
            cursor: pointer;
            font-size: 12px;
            z-index: 100;
        }

        .copy-button:hover {
            background-color: #0056b3;
        }

        pre {
            margin: 0;
            padding: 20px;
            border-radius: 5px;
            background-color: #1E1E1E;
            overflow-x: auto;
        }

        code {
            font-family: 'Consolas', 'Monaco', 'Courier New', monospace;
            font-size: 14px;
            line-height: 1.5;
        }

        /* Button Styles */
        .edit-button {
            display: inline-block;
            margin-top: 20px;
            padding: 10px 20px;
            background-color: #28a745;
            color: white;
            text-decoration: none;
            border-radius: 5px;
            font-size: 14px;
        }

        .edit-button:hover {
            background-color: #218838;
        }

        .delete-button {
            display: inline-block;
            margin-top: 20px;
            margin-left: 10px;
            padding: 10px 20px;
            background-color: #dc3545;
            color: white;
            text-decoration: none;
            border-radius: 5px;
            font-size: 14px;
        }

        .delete-button:hover {
            background-color: #c82333;
        }

        .admin-buttons {
            margin-top: 20px;
            margin-bottom: 20px;
        }

.description-pre {
    white-space: normal; /* Normal white-space for better wrapping */
    overflow-x: auto;
    font-family: 'Consolas', 'Monaco', 'Courier New', monospace;
    padding: 15px; /* Slightly reduced padding */
    background-color: #1E1E1E;
    border-radius: 5px;
    color: #ffffff;
    line-height: 1.4; /* Adjusted line height for readability */
}

.description-pre p {
    margin: 0.8em 0; /* Slightly reduced margin */
}

.description-pre pre {
    background-color: #2d2d2d;
    padding: 10px; /* Reduced padding */
    margin: 0.8em 0; /* Reduced margin */
    border-radius: 4px;
    white-space: pre;
}

.description-pre code {
    background-color: #2d2d2d; /* Highlight inline code */
    padding: 2px 4px;
    border-radius: 3px;
    color: #dcdcaa;
    font-family: 'Consolas', 'Monaco', 'Courier New', monospace;
    font-size: 90%; /* Slightly smaller for inline */
}

.description-pre h1,
.description-pre h2,
.description-pre h3,
.description-pre h4,
.description-pre h5,
.description-pre h6 {
    margin-top: 1.2em;
    margin-bottom: 0.4em; /* Compact spacing */
    font-weight: bold;
}

.description-pre blockquote {
    border-left: 3px solid #444;
    margin: 1em 0;
    padding-left: 1em;
    color: #aaa;
    font-style: italic;
}

.description-pre ul,
.description-pre ol {
    padding-left: 1.5em; /* Reduced indentation */
    margin: 0.8em 0; /* Compact spacing */
}

.description-pre li {
    margin: 0.4em 0; /* Compact spacing for list items */
}

.description-pre table {
    border-collapse: collapse;
    margin: 1em 0;
    width: 100%;
    border: 1px solid #444; /* Added border for tables */
}

.description-pre th,
.description-pre td {
    padding: 8px;
    text-align: left;
    border: 1px solid #444;
}

.description-pre th {
    background-color: #2d2d2d;
}

.description-pre hr {
    border: none;
    border-top: 1px solid #444;
    margin: 1.5em 0; /* Reduced margin for compactness */
}


    </style>
</head>
<body>
    <header>
        <h1>Solution: <?= htmlspecialchars($writeup['title']) ?></h1>
    </header>
    <nav>
        <a href="../index.php">Home</a>
        <a href="../problems.php">Problems</a>
        <a href="../view_pdfs.php">View PDFs</a>
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

        <h2 class="problem-description">Problem Description</h2>
        <div class="description-pre">
            <?= $descriptionHtml ?>
        </div>

        <h2>Solution Code</h2>
        <?php if (!empty($fileContent)): ?>
            <div class="code-container">
                <button class="copy-button">Copy Code</button>
                <pre><code class="language-<?= htmlspecialchars($writeup['language']) ?>"><?= htmlspecialchars($fileContent) ?></code></pre>
            </div>
        <?php elseif (!empty($writeup['code_text'])): ?>
            <div class="code-container">
                <button class="copy-button">Copy Code</button>
                <pre><code class="language-<?= htmlspecialchars($writeup['language']) ?>"><?= htmlspecialchars($writeup['code_text']) ?></code></pre>
            </div>
        <?php else: ?>
            <p>No code available.</p>
        <?php endif; ?>

        <?php if (isset($_SESSION['user']) && $_SESSION['is_admin'] == 1): ?>
            <div class="admin-buttons">
                <a href="edit_writeup.php?id=<?= $problemId ?>" class="edit-button">Edit Write-Up</a>
                <a href="delete_problem.php?id=<?= $problemId ?>" class="delete-button" onclick="return confirm('Are you sure you want to delete this write-up?');">Delete Write-Up</a>
            </div>
        <?php endif; ?>
    </div>
    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>