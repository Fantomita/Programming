<?php
session_start();

if (!isset($_SESSION['user']) || $_SESSION['is_admin'] != 1) {
    header('Location: ../index.php'); // Redirect if not logged in as admin
    exit;
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $categoryId = $_POST['category_id'];

    try {
        // Connect to the database
        $pdo = new PDO('sqlite:/var/www/db/problems.db');
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        // Delete the category (problems will be deleted automatically due to cascading)
        $stmt = $pdo->prepare('DELETE FROM categories WHERE id = ?');
        $stmt->execute([$categoryId]);

        // Redirect back to admin panel or success page
        header('Location: admin_panel.php?message=Category+deleted+successfully');
        exit;
    } catch (PDOException $e) {
        echo "Error: " . $e->getMessage();
    }
}
?>
