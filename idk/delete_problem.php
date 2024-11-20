<?php
session_start();

// Check if the user is logged in and retrieve the user info
if (!isset($_SESSION['user'])) {
    header("Location: ../login/login.php");  // Redirect to login if not logged in
    exit();
}

$username = $_SESSION['user'];

try {
    // Open the SQLite database and check the user's admin status
    $pdo = new PDO('sqlite:/var/www/db/users.db');  // Path to users database
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Get the user's admin status from the database
    $stmt = $pdo->prepare("SELECT is_admin FROM users WHERE username = ?");
    $stmt->execute([$username]);
    $user = $stmt->fetch(PDO::FETCH_ASSOC);

    // If the user is not an admin, show an error message and stop further execution
    if (!$user || $user['is_admin'] != 1) {
        echo "You are not authorized to delete problems.";
        exit();
    }
} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
    exit();
}

if (isset($_GET['id'])) {
    $problem_id = $_GET['id'];

    try {
        // Connect to the problems database
        $pdo = new PDO('sqlite:/var/www/db/problems.db');
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        // Prepare the delete statement
        $stmt = $pdo->prepare('DELETE FROM "write_ups" WHERE id = ?');
        $stmt->execute([$problem_id]);

        // Redirect to the problem list page after successful deletion
        header("Location: problems.php");
        exit();
    } catch (PDOException $e) {
        echo "Error: " . $e->getMessage();
        exit();
    }
} else {
    echo "Problem ID is missing.";
}
?>
