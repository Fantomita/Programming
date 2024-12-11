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
        <p>This website is my personal archive, where I store various resources, including PDFs, notes, code snippets, and other interesting content that I’ve gathered over time. The site is organized into categories to help you easily find what you're looking for.</p>

        <h3>Why This Archive?</h3>
        <p>The goal of this archive is to keep all my resources in one place for easy access and reference. Whether it’s for future study, inspiration, or just organizing my work, this site helps me keep track of a variety of different materials across several topics, from competitive programming to other interests.</p>

        <h3>What You'll Find Here</h3>
        <p>On this site, you’ll find a range of materials including:</p>
        <ul>
            <li>PDFs on various topics, categorized for easy browsing</li>
            <li>Notes and write-ups for personal reference</li>
            <li>Code snippets and solutions for different challenges I've worked on</li>
            <li>Other interesting files and resources I've collected over time</li>
        </ul>

        <h3>Technologies Used</h3>
        <ul>
            <li>PHP for backend development</li>
            <li>SQLite for storing file and category data</li>
            <li>HTML, CSS, and JavaScript for the frontend</li>
            <li>PHP sessions for user management</li>
            <li>Built on a Raspberry Pi Zero W for personal use</li>
        </ul>

        <h3>Built with AI Assistance</h3>
        <p>This website was built entirely with the help of AI. The majority of the content and structure was created using ChatGPT, an AI language model developed by OpenAI, and Google Gemini AI Pro, which contributed to refining the website's design and functionality.</p>

        <h3>Performance Notice</h3>
        <p>This site is hosted on a Raspberry Pi Zero W, a small single-board computer. While the site is functional and reliable, users may experience slower performance compared to more powerful servers, especially when dealing with large files or high traffic periods.</p>

        <h3>Contact</h3>
        <p>If you have any questions, suggestions, or feedback about this archive, feel free to reach out to me. A contact page will be available soon for more direct communication.</p>
    </div>
    <footer onclick="window.location.href='/games/index.php'">
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
