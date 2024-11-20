<?php
session_start();
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Competitive Programming Solutions</title>
    <link rel="stylesheet" href="../styles/main.css">
</head>
<body>
    <header>
        <h1>Competitive Programming Solutions</h1>
    </header>
    <nav>
        <a href="index.php">Home</a>
        <a href="problems.php">Problems</a>
        <a href="about.php">About</a>
        
        <?php
        // Check if the user is logged in and retrieve the user info from the database
        if (isset($_SESSION['user'])) {
            $username = $_SESSION['user'];

            try {
                // Open the SQLite database and check the user's admin status
                $pdo = new PDO('sqlite:db/users.db'); // Adjust path if needed
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
                echo "Error: " . $e->getMessage();
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
        <h2>Welcome to My Competitive Programming Site!</h2>
        <p>Here you'll find solutions and write-ups for various competitive programming problems I've solved. Feel free to explore!</p>
    </div>
    <footer onclick="window.location.href='/games/index.php'">
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
