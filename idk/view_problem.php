<?php
session_start();

// Check if the problem ID is passed in the URL
if (!isset($_GET['id'])) {
    header('Location: problems.php');  // Redirect to the problems list if no ID is provided
    exit;
}

// Get the problem ID from the URL
$problem_id = (int)$_GET['id'];

try {
    // Connect to SQLite database
    $pdo = new PDO('sqlite:/var/www/db/problems.db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Query to fetch the problem details from the database
    $stmt = $pdo->prepare("SELECT * FROM write_ups WHERE id = ?");
    $stmt->execute([$problem_id]);
    $problem = $stmt->fetch(PDO::FETCH_ASSOC);

    // If no problem is found, redirect to the problems list
    if (!$problem) {
        header('Location: problems.php');
        exit;
    }

    // If the code is stored in a file, load the file content
    $code = '';
    if ($problem['code_file']) {
        $code = file_get_contents($problem['code_file']);
    }

} catch (PDOException $e) {
    echo "Error: " . $e->getMessage();
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo htmlspecialchars($problem['title']); ?></title>
    <link rel="stylesheet" href="../styles/main.css">
    <!-- Include highlight.js for syntax highlighting -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.7.0/styles/default.min.css">
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.7.0/highlight.min.js"></script>
    <script>hljs.highlightAll();</script>
</head>
<body>
    <header>
        <h1><?php echo htmlspecialchars($problem['title']); ?></h1>
    </header>
    <nav>
        <a href="../index.php">Home</a>
        <a href="../problems.php">Problems</a>
        <a href="../about.php">About</a>
        
        <?php
        if (isset($_SESSION['user'])) {
            echo '<a href="/login/logout.php">Logout</a>';
        } else {
            echo '<a href="/login/login.php">Login</a>';
        }
        ?>
    </nav>
    <div class="container">
        <h2>Problem Details</h2>
        
        <p><strong>Problem Link:</strong> <a href="<?php echo htmlspecialchars($problem['link']); ?>" target="_blank"><?php echo htmlspecialchars($problem['link']); ?></a></p>
        
        <h3>Walkthrough</h3>
        <p><?php echo nl2br(htmlspecialchars($problem['description'])); ?></p>
        
        <h3>Code</h3>
        <?php if ($code): ?>
            <pre><code class="<?php echo htmlspecialchars($problem['language']); ?>"><?php echo htmlspecialchars($code); ?></code></pre>
        <?php else: ?>
            <p>No code available for this problem.</p>
        <?php endif; ?>
    </div>
    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
