<?php
session_start();

try {
    // Connect to SQLite database for PDFs
    $pdo = new PDO('sqlite:/var/www/db/pdfs.db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Get the selected category_id from the query string (if available)
    $category_id = isset($_GET['category_id']) ? $_GET['category_id'] : '';

    // Fetch all categories and sort them by name
    $category_stmt = $pdo->query("SELECT * FROM categories ORDER BY name ASC");
    $categories = $category_stmt->fetchAll(PDO::FETCH_ASSOC);

    // Handle displaying PDFs if category is selected
    if ($category_id) {
        // Fetch PDFs in the selected category, sorted by title
        $query = "SELECT * FROM pdfs WHERE category_id = :category_id ORDER BY title ASC";
        $stmt = $pdo->prepare($query);
        $stmt->bindParam(':category_id', $category_id, PDO::PARAM_INT);
        $stmt->execute();
        $pdfs = $stmt->fetchAll(PDO::FETCH_ASSOC);
    }

    // Handle PDF deletion
    if (isset($_GET['delete_pdf_id']) && isset($_SESSION['user'])) {
        // Get the PDF id to delete
        $pdf_id_to_delete = $_GET['delete_pdf_id'];

        // Get the file path of the PDF to delete
        $pdf_stmt = $pdo->prepare("SELECT file_path FROM pdfs WHERE id = :id");
        $pdf_stmt->bindParam(':id', $pdf_id_to_delete, PDO::PARAM_INT);
        $pdf_stmt->execute();
        $pdf_to_delete = $pdf_stmt->fetch(PDO::FETCH_ASSOC);

        if ($pdf_to_delete) {
            // Delete the file from the server
            $file_path = $_SERVER['DOCUMENT_ROOT'] . $pdf_to_delete['file_path'];
            if (file_exists($file_path)) {
                unlink($file_path); // Remove the PDF file from the server
            }

            // Delete the PDF record from the database
            $delete_stmt = $pdo->prepare("DELETE FROM pdfs WHERE id = :id");
            $delete_stmt->bindParam(':id', $pdf_id_to_delete, PDO::PARAM_INT);
            $delete_stmt->execute();

            // Redirect to refresh the page after deletion
            header("Location: view_pdfs.php");
            exit();
        }
    }

} catch (Exception $e) {
    $errorMessage = $e->getMessage();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>View PDFs</title>
    <link rel="stylesheet" href="../styles/main.css">
</head>
<body>
    <header>
        <h1>View PDFs</h1>
    </header>
    <nav>
        <a href="index.php">Home</a>
        <a href="problems.php">Problems</a>
        <a href="view_pdfs.php">View PDFs</a>
        <a href="about.php">About</a>

        <?php
        // Check if the user is logged in
        if (isset($_SESSION['user'])) {
            echo '<a href="upload_pdf.php">Upload PDF</a>';
        }
        ?>

        <?php if (!isset($_SESSION['user'])): ?>
            <a href="/login/login.php">Login</a>
        <?php else: ?>
            <a href="/login/logout.php">Logout</a>
        <?php endif; ?>
    </nav>

    <div class="container">
        <?php if (!$category_id): ?>
            <!-- Show Categories if no category is selected -->
            <h2>Available Categories</h2>
            <?php if (isset($errorMessage)): ?>
                <p style="color: red;"><?= htmlspecialchars($errorMessage) ?></p>
            <?php elseif (empty($categories)): ?>
                <p>No categories available.</p>
            <?php else: ?>
                <ul>
                    <?php foreach ($categories as $category): ?>
                        <li>
                            <a href="view_pdfs.php?category_id=<?= htmlspecialchars($category['id']) ?>">
                                <?= htmlspecialchars($category['name']) ?>
                            </a>
                        </li>
                    <?php endforeach; ?>
                </ul>
            <?php endif; ?>
        <?php else: ?>
            <!-- Show PDFs if category is selected -->
            <?php
                $category_name_stmt = $pdo->prepare("SELECT name FROM categories WHERE id = :category_id");
                $category_name_stmt->bindParam(':category_id', $category_id, PDO::PARAM_INT);
                $category_name_stmt->execute();
                $category_name = $category_name_stmt->fetch(PDO::FETCH_ASSOC);
            ?>

            <h3>PDFs in Category: <?= htmlspecialchars($category_name['name']) ?></h3>

            <ul>
                <?php foreach ($pdfs as $pdf): ?>
                    <li>
                        <a href="<?= htmlspecialchars($pdf['file_path']) ?>" target="_blank">
                            <?= htmlspecialchars($pdf['title']) ?>
                        </a>
                        <?php if (isset($_SESSION['user'])): ?>
                            <a href="view_pdfs.php?delete_pdf_id=<?= $pdf['id'] ?>" 
                               onclick="return confirm('Are you sure you want to delete this PDF?');">
                                Delete
                            </a>
                        <?php endif; ?>
                    </li>
                <?php endforeach; ?>
            </ul>

            <!-- Back Button to Categories -->
            <a href="view_pdfs.php">Back to Categories</a>
        <?php endif; ?>
    </div>

    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
