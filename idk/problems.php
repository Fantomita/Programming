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
    <script>
        document.addEventListener("DOMContentLoaded", function () {
            const searchInput = document.querySelector('input[name="search"]');
            const resultsContainer = document.querySelector('ul');
            const categoryFilter = document.querySelector('select[name="category_id"]');
            const languageFilter = document.querySelector('select[name="language"]');

            function fetchAndDisplayResults() {
                const searchQuery = searchInput.value;
                const categoryId = categoryFilter.value;
                const language = languageFilter.value;

                const url = `ajax_search.php?search=${encodeURIComponent(searchQuery)}&category_id=${encodeURIComponent(categoryId)}&language=${encodeURIComponent(language)}`;

                fetch(url)
                    .then(response => response.json())
                    .then(data => {
                        resultsContainer.innerHTML = ""; // Clear previous results
                        if (data.length === 0) {
                            resultsContainer.innerHTML = "<li>No results found</li>";
                        } else {
                            data.forEach((item, index) => {
                                const languageText = item.language === "cpp" ? "C++" : item.language;
                                resultsContainer.innerHTML += `
                                    <li>
                                        <span class="problem-number">${index + 1}.</span>
                                        <a href="view_writeup.php?id=${item.id}">${item.title}</a>
                                        <span class="category">(${item.category_name})</span>
                                        <span class="language">[${languageText}]</span>
                                    </li>
                                `;
                            });
                        }
                    })
                    .catch(error => {
                        console.error("Error fetching search results:", error);
                        resultsContainer.innerHTML = "<li>Error loading results</li>";
                    });
            }

            searchInput.addEventListener('input', fetchAndDisplayResults);
            categoryFilter.addEventListener('change', fetchAndDisplayResults);
            languageFilter.addEventListener('change', fetchAndDisplayResults);

            fetchAndDisplayResults(); // Initial fetch of results
        });
    </script>
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
        if (isset($_SESSION['user'])) {
            $username = $_SESSION['user'];

            try {
                $pdo = new PDO('sqlite:db/users.db');
                $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

                $stmt = $pdo->prepare("SELECT is_admin FROM users WHERE username = ?");
                $stmt->execute([$username]);
                $user = $stmt->fetch(PDO::FETCH_ASSOC);

                if ($user && $user['is_admin'] == 1) {
                    echo '<a href="/login/admin.php">Admin Panel</a>';
                    echo '<a href="add_writeup.php" class="button">Add New Writeup</a>';
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

        <!-- Category Filter -->
        <div class="filter">
            <label for="category">Filter by Category:</label>
            <select name="category_id" id="category_id">
                <option value="">-- All Categories --</option>
                <?php
                try {
                    $pdo = new PDO('sqlite:/var/www/db/problems.db');
                    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                    $stmt = $pdo->query("SELECT * FROM categories");
                    $categories = $stmt->fetchAll(PDO::FETCH_ASSOC);

                    foreach ($categories as $category) {
                        echo "<option value='{$category['id']}'>" . htmlspecialchars($category['name']) . "</option>";
                    }
                } catch (PDOException $e) {
                    echo "Error fetching categories: " . $e->getMessage();
                }
                ?>
            </select>
        </div>

        <!-- Language Filter -->
        <div class="filter">
            <label for="language">Filter by Language:</label>
            <select name="language" id="language">
                <option value="">-- All Languages --</option>
                <option value="PHP">PHP</option>
                <option value="Python">Python</option>
                <option value="C++">C++</option>
                <option value="Java">Java</option>
            </select>
        </div>

        <!-- Search Bar -->
        <div class="filter">
            <label for="search">Search by Problem Name:</label>
            <input type="text" name="search" id="search" placeholder="Search for problems...">
        </div>

        <ul>
            <!-- AJAX Results will be appended here -->
        </ul>
    </div>
    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
