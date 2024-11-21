<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>About</title>
    <link rel="stylesheet" href="../styles/main.css">
</head>
<body>
    <header>
        <h1>About This Website</h1>
    </header>
    <nav>
        <a href="../index.php">Home</a>
        <a href="../problems.php">Problems</a>
        <a href="../about.php">About</a>

        <?php
        // Check if the user is logged in and retrieve the user info from the session
        if (isset($_SESSION['user'])) {
            $username = $_SESSION['user'];

            try {
                // Open the SQLite database and check the user's admin status
                $pdo = new PDO('sqlite:/var/www/db/users.db'); // Path to users database
                $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                // Get the user's admin status from the database
                $stmt = $pdo->prepare("SELECT is_admin FROM users WHERE username = ?");
                $stmt->execute([$username]);
                $user = $stmt->fetch(PDO::FETCH_ASSOC);

                if ($user && $user['is_admin'] == 1) {
                    // If user is admin, show the Admin Panel link
                    echo '<a href="/login/admin.php">Admin Panel</a>';
                }
            } catch (PDOException $e) {
                echo "<p>Error: " . $e->getMessage() . "</p>";
            }
        }
        ?>

        <?php if (!isset($_SESSION['user'])): ?>
            <a href="/login/login.php">Login</a>
        <?php else: ?>
            <a href="/login/logout.php">Logout</a>
        <?php endif; ?>
    </nav>
    <div class="container">
        <h2>Welcome to My Code Repository</h2>
        <p>This website is a personal project designed to help me share my solutions and code snippets for various problems. The content is primarily for my own understanding and reference, as I work through different coding challenges and problems.</p>
        <p>On this site, you'll find solutions to programming problems that I have solved, along with detailed write-ups explaining the problem-solving approach, the steps I took to arrive at the solution, and code snippets in different languages.</p>
        <p>As this site is for my personal use, others cannot share their code or submit new write-ups. However, feel free to browse through the problems and solutions if you're looking for similar problems or insights into my coding style and methods.</p>

        <h3>Why This Site?</h3>
        <p>I've created this site to organize my thoughts and learnings around coding challenges. It's a way for me to document and reinforce my understanding of different algorithms, data structures, and programming languages.</p>
        <p>The goal is to provide clear explanations and well-documented solutions to help me revisit these problems and improve my coding skills over time.</p>

        <h3>Technologies Used</h3>
        <ul>
            <li>PHP for backend development</li>
            <li>SQLite for storing problem data</li>
            <li>HTML, CSS, and JavaScript for the frontend</li>
            <li>PHP sessions for user management</li>
            <li>Built entirely by ChatGPT, an AI model by OpenAI</li>
        </ul>

        <h3>Performance Notice</h3>
        <p>Please note that this website is hosted on a spare Raspberry Pi Zero W. As such, users may experience slower performance compared to websites hosted on more powerful servers. This is a personal project, and the performance limitations of the Raspberry Pi Zero W may affect loading times and overall responsiveness, especially during high traffic periods.</p>

        <h3>Contact</h3>
        <p>If you have any questions or feedback about my solutions, feel free to reach out to me through the contact page (coming soon).</p>
    </div>
    <footer onclick="window.location.href='/games/index.php'">
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
