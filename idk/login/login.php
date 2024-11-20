<?php
ini_set('session.cookie_path', '/');
session_start();

if (isset($_SESSION['user'])) {
    header('Location: ../index.php'); // Redirect if already logged in
    exit;
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    try {
        // Ensure correct database path
        $pdo = new PDO('sqlite:../db/users.db'); // Adjust the path as needed
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        // Fetch user from the database
        $stmt = $pdo->prepare("SELECT * FROM users WHERE username = ?");
        $stmt->execute([$username]);
        $user = $stmt->fetch(PDO::FETCH_ASSOC);

        if ($user && password_verify($password, $user['password'])) {
            // Password is correct, start a session
            $_SESSION['user'] = $username;
            $_SESSION['is_admin'] = $user['is_admin']; // Store the admin status in session
            header('Location: ../index.php'); // Redirect to homepage
            exit;
        } else {
            $error = "Invalid credentials."; // Show error message if authentication fails
        }
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
    <title>Login - Competitive Programming Solutions</title>
    <link rel="stylesheet" href="../styles/main.css">
</head>
<body>
    <header>
        <h1>Login to Competitive Programming Solutions</h1>
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
                // Open the SQLite database and check the user's admin status
                $pdo = new PDO('sqlite:../db/users.db'); // Adjust path if necessary
                $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                // Get the user's admin status from the database
                $stmt = $pdo->prepare("SELECT is_admin FROM users WHERE username = ?");
                $stmt->execute([$username]);
                $user = $stmt->fetch(PDO::FETCH_ASSOC);

                if ($user && $user['is_admin'] == 1) {
                    // If user is admin, show the Admin Panel link
                    echo '<a href="admin.php">Admin Panel</a>';
                }
            } catch (PDOException $e) {
                echo "Error: " . $e->getMessage();
            }
        }
        ?>

        <?php if (!isset($_SESSION['user'])): ?>
            <a href="login.php">Login</a>
        <?php else: ?>
            <a href="logout.php">Logout</a>
        <?php endif; ?>
    </nav>
    <div class="container">
        <h2>Login</h2>
        <?php if (isset($error)): ?>
            <p style="color: red;"><?php echo $error; ?></p>
        <?php endif; ?>
        <form method="POST" action="login.php">
            <label for="username">Username:</label>
            <input type="text" name="username" id="username" required><br>
            <label for="password">Password:</label>
            <input type="password" name="password" id="password" required><br>
            <button type="submit">Login</button>
        </form>
    </div>
    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
