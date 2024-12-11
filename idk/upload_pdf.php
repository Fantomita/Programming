<?php
session_start();

if (!isset($_SESSION['user']) || $_SESSION['is_admin'] != 1) {
    header('Location: ../index.php'); // Redirect if not logged in as admin
    exit;
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    try {
        // Connect to SQLite database
        $pdo = new PDO('sqlite:/var/www/db/pdfs.db');
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        // Handle category creation
        if (isset($_POST['create_category'])) {
            $category_name = trim($_POST['category_name']);
            if (empty($category_name)) {
                throw new Exception("Category name cannot be empty.");
            }

            // Insert the new category into the database
            $stmt = $pdo->prepare("INSERT INTO categories (name) VALUES (?)");
            $stmt->execute([$category_name]);

            $successMessage = "Category created successfully!";
        }

        // Handle category deletion
        if (isset($_POST['delete_category_id'])) {
            $category_id = $_POST['delete_category_id'];

            // Check if the category is in use by any PDFs
            $stmt = $pdo->prepare("SELECT COUNT(*) FROM pdfs WHERE category_id = ?");
            $stmt->execute([$category_id]);
            $count = $stmt->fetchColumn();

            if ($count > 0) {
                throw new Exception("Category cannot be deleted because it is in use.");
            }

            // Delete the category from the database
            $stmt = $pdo->prepare("DELETE FROM categories WHERE id = ?");
            $stmt->execute([$category_id]);

            $successMessage = "Category deleted successfully!";
        }

        // Handle PDF upload
        if (isset($_FILES['pdf_file']) && $_FILES['pdf_file']['error'] === UPLOAD_ERR_OK) {
            // Define the upload directory (web-accessible path)
            $uploadDir = '/var/www/uploads/pdfs/';
            $webAccessibleDir = '/uploads/pdfs/'; // Relative path for URLs
            $fileName = uniqid() . '_' . basename($_FILES['pdf_file']['name']); // Avoid filename conflicts
            $uploadFilePath = $uploadDir . $fileName;

            // Validate file type
            if (mime_content_type($_FILES['pdf_file']['tmp_name']) !== 'application/pdf') {
                throw new Exception("Invalid file type. Only PDFs are allowed.");
            }

            // Ensure the upload directory exists
            if (!is_dir($uploadDir)) {
                mkdir($uploadDir, 0755, true);
            }

            // Move uploaded file to the target directory
            if (!move_uploaded_file($_FILES['pdf_file']['tmp_name'], $uploadFilePath)) {
                throw new Exception("Failed to save the uploaded file.");
            }

            // Get the category from the form
            $category_id = $_POST['category_id'];

            // Insert record into database (store the relative path for URL resolution)
            $stmt = $pdo->prepare("INSERT INTO pdfs (title, file_path, category_id) VALUES (?, ?, ?)");
            $stmt->execute([$_POST['title'], $webAccessibleDir . $fileName, $category_id]);

            $successMessage = "PDF uploaded successfully!";
        } else {
            throw new Exception("No file uploaded or an error occurred.");
        }
    } catch (Exception $e) {
        $errorMessage = $e->getMessage();
    }
}

// Fetch all categories for the dropdown and deletion
try {
    $pdo = new PDO('sqlite:/var/www/db/pdfs.db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $category_stmt = $pdo->query("SELECT * FROM categories");
    $categories = $category_stmt->fetchAll(PDO::FETCH_ASSOC);
} catch (PDOException $e) {
    $categoryErrorMessage = "Failed to fetch categories.";
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Upload PDF</title>
    <link rel="stylesheet" href="../styles/main.css">
</head>
<body>
    <header>
        <h1>Upload PDF</h1>
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
                    // Admin panel and upload PDF link
                    echo '<a href="upload_pdf.php">Upload PDF</a>';
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
        <h2>Upload a New PDF</h2>
        <?php if (isset($successMessage)): ?>
            <p style="color: green;"><?= htmlspecialchars($successMessage) ?></p>
        <?php elseif (isset($errorMessage)): ?>
            <p style="color: red;"><?= htmlspecialchars($errorMessage) ?></p>
        <?php elseif (isset($categoryErrorMessage)): ?>
            <p style="color: red;"><?= htmlspecialchars($categoryErrorMessage) ?></p>
        <?php endif; ?>
        
        <!-- Create new category form -->
        <h3>Create New Category</h3>
        <form action="upload_pdf.php" method="post">
            <div>
                <label for="category_name">Category Name:</label>
                <input type="text" name="category_name" id="category_name" required>
            </div>
            <button type="submit" name="create_category">Create Category</button>
        </form>

        <!-- PDF upload form -->
        <h3>Upload a New PDF</h3>
        <form action="upload_pdf.php" method="post" enctype="multipart/form-data">
            <div>
                <label for="title">PDF Title:</label>
                <input type="text" name="title" id="title" required>
            </div>
            <div>
                <label for="pdf_file">Select PDF:</label>
                <input type="file" name="pdf_file" id="pdf_file" accept="application/pdf" required>
            </div>
            <div>
                <label for="category_id">Category:</label>
                <select name="category_id" id="category_id" required>
                    <option value="">-- Select a Category --</option>
                    <?php foreach ($categories as $category): ?>
                        <option value="<?= htmlspecialchars($category['id']) ?>">
                            <?= htmlspecialchars($category['name']) ?>
                        </option>
                    <?php endforeach; ?>
                </select>
            </div>
            <button type="submit">Upload</button>
        </form>

        <!-- Existing categories and delete option -->
        <h3>Existing Categories</h3>
        <table>
            <thead>
                <tr>
                    <th>Category Name</th>
                    <th>Actions</th>
                </tr>
            </thead>
            <tbody>
                <?php foreach ($categories as $category): ?>
                    <tr>
                        <td><?= htmlspecialchars($category['name']) ?></td>
                        <td>
                            <form action="upload_pdf.php" method="post" onsubmit="return confirm('Are you sure you want to delete this category?');">
                                <input type="hidden" name="delete_category_id" value="<?= htmlspecialchars($category['id']) ?>">
                                <button type="submit">Delete</button>
                            </form>
                        </td>
                    </tr>
                <?php endforeach; ?>
            </tbody>
        </table>
    </div>
    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
