<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Personal Archive</title>
    <link rel="stylesheet" href="../styles/main.css">
</head>
<body>
    <header>
        <h1>Welcome to My Personal Archive</h1>
    </header>
    <nav>
        <a href="index.php">Home</a>
        <a href="problems.php">Problems</a>
        <a href="view_pdfs.php">View PDFs</a>
        <a href="about.php">About</a>

        <?php
        // Check if the user is logged in and retrieve the user info from the database
        if (isset($_SESSION['user'])) {
            $username = $_SESSION['user'];

            try {
                // Open the SQLite database and check the user's admin status
                $pdo = new PDO('sqlite:db/users.db'); // Adjust path if needed
                $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                // Get the user's admin status from the database securely
                $stmt = $pdo->prepare("SELECT is_admin FROM users WHERE username = :username");
                $stmt->bindParam(':username', $username, PDO::PARAM_STR); // Bind parameters to avoid SQL injection
                $stmt->execute();
                $user = $stmt->fetch(PDO::FETCH_ASSOC);

                if ($user && $user['is_admin'] == 1) {
                    //echo '<a href="videos.php">Videos</a>';
                    echo '<a href="/login/admin.php">Admin Panel</a>';
                }
            } catch (PDOException $e) {
                // Log the error in production but don't expose detailed information to the user
                error_log("Database error: " . $e->getMessage()); // Log the error for debugging
                echo "An error occurred, please try again later."; // Generic error message for users
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
        <h2>Welcome to My Personal Archive!</h2>
        <p>Explore my archive where I store various resources, from competitive programming solutions to other interesting things I've worked on or collected over time.</p>
        <pre>
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠤⠒⠒⠒⠒⠢⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠈⢦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⠀⠀⠀⠀⠀⡤⢄⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡰⠃⠀⠀⠀⠀⠀⠀⠀⣼⡆⠀⢀⢀⠀⠸⡟⡇⠀⠀⡰⢾⢁⢸⣄⠀
⠀⠀⠀⠀⠀⠀⠀⣰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠙⠈⠀⠈⠉⠀⠀⠀⢸⠀⠀⡝⡆⠚⠠⣤⠇
⠀⠀⠀⠀⠀⠀⢠⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡀⠀⠙⢸⠧⣤⠃⠀
⠀⠀⠀⠀⠀⢠⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣇⡀⣤⣼⠧⡀⠀⠀
⠀⠀⠀⠀⢠⡏⠀⠀⠀⠀⡀⠀⠀⣠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⡇⠀⣀⣧⢸⠀⠀⠀
⠀⠀⠀⢠⡞⠀⠀⠀⠀⠀⢟⠀⢀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠒⠉⠁⢸⡄⠀⠀⠀
⠀⠀⢀⡞⠀⠀⠀⠀⠀⠀⢸⠀⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠈⠀⠀⠀⠀
⠀⣠⠏⠀⠀⠀⠀⠀⠀⠀⠈⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀⠀⠀⠀⠀⠀⠀⠀
⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡏⠀⠀⠀⠀⠀⠀⠀⠀
⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠁⠀⠀⠀⠀⠀⠀⠀⠀
⠙⠶⠦⠤⠶⠖⠒⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠈⣷⠀⠀⠀⠀⢀⣤⠴⠶⣤⣀⠀⠀⣠⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠙⠲⠤⠖⠚⠉⠀⠀⠀⠀⠈⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        </pre>
    </div>
    <footer onclick="window.location.href='/games/index.php'">
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
