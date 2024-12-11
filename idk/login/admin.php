<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);

session_start();

// Ensure only the admin can access this page
if (!isset($_SESSION['user'])) {
    header('Location: login.php'); // Redirect to login if not logged in
    exit;
}

// Initialize the database connection for users (users.db)
try {
    $pdo_users = new PDO('sqlite:/var/www/db/users.db');
    $pdo_users->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
    exit;
}

// Initialize the database connection for categories (problems.db)
try {
    $pdo_problems = new PDO('sqlite:/var/www/db/problems.db');
    $pdo_problems->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
    exit;
}

// Check if the logged-in user is an admin
$username = $_SESSION['user'];
$stmt = $pdo_users->prepare("SELECT is_admin FROM users WHERE username = ?");
$stmt->execute([$username]);
$user = $stmt->fetch(PDO::FETCH_ASSOC);

if ($user['is_admin'] != 1) {
    header('Location: ../index.php'); // Redirect to homepage if not an admin
    exit;
}

// Handle user deletion
if (isset($_POST['delete_user'])) {
    $user_id_to_delete = $_POST['user_id_to_delete'];

    try {
        // Prevent deletion of the admin account
        $stmt = $pdo_users->prepare("SELECT username FROM users WHERE id = ?");
        $stmt->execute([$user_id_to_delete]);
        $user_to_delete = $stmt->fetch(PDO::FETCH_ASSOC);

        if ($user_to_delete && $user_to_delete['username'] == 'admin') {
            $error_message = "You cannot delete the admin account.";
        } else {
            $stmt = $pdo_users->prepare("DELETE FROM users WHERE id = ?");
            $stmt->execute([$user_id_to_delete]);
            $success_message = "User deleted successfully!";
        }
    } catch (PDOException $e) {
        $error_message = "Error deleting user: " . $e->getMessage();
    }
}

// Handle new user creation
if (isset($_POST['create_user'])) {
    $new_username = trim($_POST['new_username']);
    $new_password = $_POST['new_password'];
    $is_admin = $_POST['is_admin'];
    $new_password_hash = password_hash($new_password, PASSWORD_DEFAULT); // Hash the password

    try {
        // Check if the username already exists
        $stmt = $pdo_users->prepare("SELECT id FROM users WHERE username = ?");
        $stmt->execute([$new_username]);
        if ($stmt->fetch(PDO::FETCH_ASSOC)) {
            $error_message = "Username already exists.";
        } else {
            // Insert new user into the database
            $stmt = $pdo_users->prepare("INSERT INTO users (username, password, is_admin) VALUES (?, ?, ?)");
            $stmt->execute([$new_username, $new_password_hash, $is_admin]);
            $success_message = "New user created successfully!";
        }
    } catch (PDOException $e) {
        $error_message = "Error creating user: " . $e->getMessage();
    }
}

// Handle category deletion
if (isset($_POST['delete_category'])) {
    $category_id_to_delete = $_POST['category_id_to_delete'];

    try {
        $stmt = $pdo_problems->prepare("DELETE FROM categories WHERE id = ?");
        $stmt->execute([$category_id_to_delete]);
        $success_message = "Category and associated problems deleted successfully!";
    } catch (PDOException $e) {
        $error_message = "Error deleting category: " . $e->getMessage();
    }
}

// Handle new category creation
if (isset($_POST['create_category'])) {
    $new_category_name = trim($_POST['new_category_name']);

    try {
        // Check if the category name already exists
        $stmt = $pdo_problems->prepare("SELECT id FROM categories WHERE name = ?");
        $stmt->execute([$new_category_name]);
        if ($stmt->fetch(PDO::FETCH_ASSOC)) {
            $error_message = "Category already exists.";
        } else {
            // Insert new category into the database
            $stmt = $pdo_problems->prepare("INSERT INTO categories (name) VALUES (?)");
            $stmt->execute([$new_category_name]);
            $success_message = "New category created successfully!";
        }
    } catch (PDOException $e) {
        $error_message = "Error creating category: " . $e->getMessage();
    }
}

// Fetch all users for display
$stmt = $pdo_users->prepare("SELECT id, username, is_admin FROM users");
$stmt->execute();
$users = $stmt->fetchAll(PDO::FETCH_ASSOC);

// Fetch all categories for display
$stmt = $pdo_problems->prepare("SELECT id, name FROM categories");
$stmt->execute();
$categories = $stmt->fetchAll(PDO::FETCH_ASSOC);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin - Manage Users and Categories</title>
    <link rel="stylesheet" href="../styles/main.css">
</head>
<body>
    <header>
        <h1>Admin - Manage Users and Categories</h1>
    </header>
    <nav>
        <a href="../index.php">Home</a>
        <a href="../problems.php">Problems</a>
        <a href="../about.php">About</a>
        <?php if (isset($_SESSION['user'])): ?>
            <?php if ($user['is_admin'] == 1): ?>
                <a href="admin.php">Admin Panel</a>
            <?php endif; ?>
            <a href="logout.php">Logout</a>
        <?php else: ?>
            <a href="login.php">Login</a>
        <?php endif; ?>
    </nav>
    <div class="container">
        <h2>All Users</h2>
        <?php if (isset($success_message)): ?>
            <p style="color: green;"><?php echo $success_message; ?></p>
        <?php endif; ?>
        <?php if (isset($error_message)): ?>
            <p style="color: red;"><?php echo $error_message; ?></p>
        <?php endif; ?>
        <table>
            <tr>
                <th>ID</th>
                <th>Username</th>
                <th>Role</th>
                <th>Actions</th>
            </tr>
            <?php foreach ($users as $user): ?>
            <tr>
                <td><?php echo htmlspecialchars($user['id']); ?></td>
                <td><?php echo htmlspecialchars($user['username']); ?></td>
                <td><?php echo $user['is_admin'] == 1 ? 'Admin' : 'User'; ?></td>
                <td>
                    <?php if ($user['username'] != 'ghostly'): ?>
                        <form method="POST" style="display:inline;">
                            <input type="hidden" name="user_id_to_delete" value="<?php echo $user['id']; ?>">
                            <button type="submit" name="delete_user" onclick="return confirm('Are you sure you want to delete this user?')">Delete</button>
                        </form>
                    <?php endif; ?>
                </td>
            </tr>
            <?php endforeach; ?>
        </table>

        <h2>Create New User</h2>
        <form method="POST" action="admin.php">
            <label for="new_username">Username:</label>
            <input type="text" name="new_username" id="new_username" required><br>
            <label for="new_password">Password:</label>
            <input type="password" name="new_password" id="new_password" required><br>
            <label for="is_admin">Admin:</label>
            <select name="is_admin" id="is_admin">
                <option value="0">User</option>
                <option value="1">Admin</option>
            </select><br>
            <button type="submit" name="create_user">Create User</button>
        </form>

        <h2>All Categories</h2>
        <table>
            <tr>
                <th>ID</th>
                <th>Category Name</th>
                <th>Actions</th>
            </tr>
            <?php foreach ($categories as $category): ?>
            <tr>
                <td><?php echo htmlspecialchars($category['id']); ?></td>
                <td><?php echo htmlspecialchars($category['name']); ?></td>
                <td>
                    <form method="POST" style="display:inline;">
                        <input type="hidden" name="category_id_to_delete" value="<?php echo $category['id']; ?>">
                        <button type="submit" name="delete_category" onclick="return confirm('Are you sure you want to delete this category and all associated problems?')">Delete</button>
                    </form>
                </td>
            </tr>
            <?php endforeach; ?>
        </table>

        <h2>Create New Category</h2>
        <form method="POST" action="admin.php">
            <label for="new_category_name">Category Name:</label>
            <input type="text" name="new_category_name" id="new_category_name" required><br>
            <button type="submit" name="create_category">Create Category</button>
        </form>
    </div>
    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>