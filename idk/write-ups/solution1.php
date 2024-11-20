<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Solution: Two Sum</title>
    <link rel="stylesheet" href="../styles/main.css">
    <!-- highlight.js CSS -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/styles/vs-dark.min.css">
    <!-- highlight.js JavaScript -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/highlight.min.js"></script>
    <!-- VSCode Dark+ Theme for Highlight.js -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.8.0/styles/vs-dark.min.css">
    <!-- Initialize highlight.js -->
    <script>hljs.highlightAll();</script>
</head>
<body>
    <header>
        <h1>Solution: Two Sum</h1>
    </header>
    <nav>
        <a href="../index.php">Home</a>
        <a href="../problems.php">Problems</a>
        <a href="../about.php">About</a>
        
        <?php
        // Check if the user is logged in and retrieve the user info from the database
        if (isset($_SESSION['user'])) {
            $username = $_SESSION['user'];

            try {
                // Open the SQLite database in the 'db' subfolder and check the user's admin status
                $pdo = new PDO('sqlite:../db/users.db');  // Updated path to 'db/users.db'
                $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                // Get the user's admin status from the database
                $stmt = $pdo->prepare("SELECT is_admin FROM users WHERE username = ?");
                $stmt->execute([$username]);
                $user = $stmt->fetch(PDO::FETCH_ASSOC);

                if ($user && $user['is_admin'] == 1) {
                    // If user is admin, show the Admin Panel link
                    echo '<a href="../login/admin.php">Admin Panel</a>';
                }
            } catch (PDOException $e) {
                echo "Error: " . $e->getMessage();
            }
        }
        ?>

        <?php if (!isset($_SESSION['user'])): ?>
            <a href="../login/login.php">Login</a>
        <?php else: ?>
            <a href="../login/logout.php">Logout</a>
        <?php endif; ?>
    </nav>
    <div class="container">
        <h2>Problem Statement</h2>
        <p>Given an array of integers, return the indices of the two numbers such that they add up to a specific target.</p>
        <h2>Solution Code</h2>
        <pre><code class="language-cpp">
<?php
    // Load the C++ code from the external file and display it with syntax highlighting.
    $codePath = "../code/two_sum.cpp";  // Path to the code file in the 'code' subfolder
    if (file_exists($codePath)) {
        // Read the C++ file content and escape HTML characters.
        echo htmlspecialchars(file_get_contents($codePath));
    } else {
        echo "Code not found.";
    }
?>
        </code></pre>
    </div>
    <footer onclick="window.location.href='../games/snake/snake.php'">
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
