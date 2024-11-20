<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Problem List</title>
    <link rel="stylesheet" href="../styles/main.css">
    <!-- Include FontAwesome for icons (if not already included) -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.0.0-beta3/css/all.min.css">
</head>
<body>
    <header>
        <h1>Problem List</h1>
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
            <a href="../login/login.php">Login</a>
        <?php else: ?>
            <a href="../login/logout.php">Logout</a>
        <?php endif; ?>
    </nav>
    <div class="container">
        <h2>List of Problems</h2>

        <!-- Category Filter Form -->
        <form method="GET" action="problems.php">
            <label for="category">Filter by Category:</label>
            <select name="category_id" onchange="this.form.submit()">
                <option value="">-- All Categories --</option>
                <?php
                // Fetch categories
                try {
                    $pdo = new PDO('sqlite:/var/www/db/problems.db');
                    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                    $stmt = $pdo->query("SELECT * FROM categories");
                    $categories = $stmt->fetchAll(PDO::FETCH_ASSOC);

                    foreach ($categories as $category) {
                        $selected = isset($_GET['category_id']) && $_GET['category_id'] == $category['id'] ? 'selected' : '';
                        echo "<option value='{$category['id']}' $selected>" . htmlspecialchars($category['name']) . "</option>";
                    }
                } catch (PDOException $e) {
                    echo "Error fetching categories: " . $e->getMessage();
                }
                ?>
            </select>
        </form>

        <?php
        // Check if the user is logged in and if they are an admin
        if (isset($_SESSION['user'])) {
            $username = $_SESSION['user'];

            try {
                // Open the SQLite database and check the user's admin status
                $pdo = new PDO('sqlite:/var/www/db/users.db');  // Path to users database
                $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                // Get the user's admin status from the database
                $stmt = $pdo->prepare("SELECT is_admin FROM users WHERE username = ?");
                $stmt->execute([$username]);
                $user = $stmt->fetch(PDO::FETCH_ASSOC);
                
                // If the user is an admin, show the "Add New Write-Up" button
                if ($user && $user['is_admin'] == 1) {
                    echo '<a href="../add_writeup.php" class="add-button">Add New Write-Up</a>';
                }
            } catch (PDOException $e) {
                echo "Error: " . $e->getMessage();
            }
        }
        ?>

        <ul>
            <?php
            try {
                // Connect to the problems database
                $pdo = new PDO('sqlite:/var/www/db/problems.db');
                $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                // Fetch problems, filtering by category if needed
                $category_id = isset($_GET['category_id']) ? $_GET['category_id'] : null;
                $query = "SELECT write_ups.*, categories.name AS category_name 
                          FROM write_ups 
                          LEFT JOIN categories ON write_ups.category_id = categories.id";
                if ($category_id) {
                    $query .= " WHERE write_ups.category_id = :category_id";
                }
                $query .= " ORDER BY write_ups.date_created DESC";
                $stmt = $pdo->prepare($query);
                if ($category_id) {
                    $stmt->bindParam(':category_id', $category_id, PDO::PARAM_INT);
                }
                $stmt->execute();
                $write_ups = $stmt->fetchAll(PDO::FETCH_ASSOC);

                foreach ($write_ups as $write_up) {
                    echo '<li>';
                    echo '<a href="view_writeup.php?id=' . $write_up['id'] . '">' . htmlspecialchars($write_up['title']) . '</a>';
                    echo ' <span class="category">(' . htmlspecialchars($write_up['category_name']) . ')</span>';

                    // Show delete button only for admins
                    if (isset($_SESSION['user'])) {
                        $username = $_SESSION['user'];

                        try {
                            // Open the SQLite database and check the user's admin status
                            $pdo = new PDO('sqlite:/var/www/db/users.db');
                            $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                            $stmt = $pdo->prepare("SELECT is_admin FROM users WHERE username = ?");
                            $stmt->execute([$username]);
                            $user = $stmt->fetch(PDO::FETCH_ASSOC);

                            if ($user && $user['is_admin'] == 1) {
                                echo '<a href="delete_problem.php?id=' . $write_up['id'] . '" class="delete-btn" onclick="return confirm(\'Are you sure you want to delete this problem?\')"> <i class="fas fa-trash"></i> </a>';
                            }
                        } catch (PDOException $e) {
                            echo "Error: " . $e->getMessage();
                        }
                    }

                    echo '</li>';
                }
            } catch (PDOException $e) {
                echo "Error: " . $e->getMessage();
            }
            ?>
        </ul>
    </div>
    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
