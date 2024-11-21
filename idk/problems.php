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

    <script>
        document.addEventListener("DOMContentLoaded", function () {
        const searchInput = document.querySelector('input[name="search"]');
        const resultsContainer = document.querySelector('ul');
        const categoryFilter = document.querySelector('select[name="category_id"]');
        const languageFilter = document.querySelector('select[name="language"]');

        // Function to fetch and update the results
        function fetchAndDisplayResults(query = "") {
            const category = categoryFilter.value;
            const language = languageFilter.value;

            // Build URL with all filters and search query
            const url = `ajax_search.php?search=${encodeURIComponent(query)}&category_id=${encodeURIComponent(category)}&language=${encodeURIComponent(language)}`;

            fetch(url)
                .then(response => response.json())
                .then(data => {
                    // Clear the current list
                    resultsContainer.innerHTML = "";

                    if (data.length === 0) {
                        resultsContainer.innerHTML = "<li>No results found</li>";
                    } else {
                        data.forEach((item, index) => {
                            const language = item.language === "cpp" ? "C++" : item.language;
                            resultsContainer.innerHTML += `
                                <li>
                                    <span class="problem-number">${index + 1}.</span>
                                    <a href="view_writeup.php?id=${item.id}">${item.title}</a>
                                    <span class="category">(${item.category_name})</span>
                                    <span class="language">[${language}]</span>
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

        // Fetch and display all problems initially
        fetchAndDisplayResults();

        // Add event listeners for dynamic updates
        searchInput.addEventListener('input', function () {
            fetchAndDisplayResults(searchInput.value);
        });

        categoryFilter.addEventListener('change', function () {
            fetchAndDisplayResults(searchInput.value);
        });

        languageFilter.addEventListener('change', function () {
            fetchAndDisplayResults(searchInput.value);
        });
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

        <!-- Programming Language Filter Form (below category filter) -->
        <form method="GET" action="problems.php">
            <label for="language">Filter by Language:</label>
            <select name="language" onchange="this.form.submit()">
                <option value="">-- All Languages --</option>
                <option value="PHP" <?php echo (isset($_GET['language']) && $_GET['language'] == 'PHP') ? 'selected' : ''; ?>>PHP</option>
                <option value="Python" <?php echo (isset($_GET['language']) && $_GET['language'] == 'Python') ? 'selected' : ''; ?>>Python</option>
                <option value="C++" <?php echo (isset($_GET['language']) && $_GET['language'] == 'C++') ? 'selected' : ''; ?>>C++</option>
                <option value="Java" <?php echo (isset($_GET['language']) && $_GET['language'] == 'Java') ? 'selected' : ''; ?>>Java</option>
                <!-- Add more languages as needed -->
            </select>
        </form>

        <!-- Search Bar -->
        <form>
            <label for="search">Search by Problem Name:</label>
            <input type="text" name="search" placeholder="Search for problems...">
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

                // Get the filter and search parameters
                $category_id = isset($_GET['category_id']) ? $_GET['category_id'] : null;
                $language = isset($_GET['language']) ? $_GET['language'] : null;
                $search = isset($_GET['search']) ? $_GET['search'] : '';

                // Adjust the language to 'cpp' for C++ filter selection
                if ($language === 'C++') {
                    $language = 'cpp';
                }

                $query = "SELECT write_ups.*, categories.name AS category_name 
                        FROM write_ups 
                        LEFT JOIN categories ON write_ups.category_id = categories.id";
                $conditions = [];

                if ($category_id) {
                    $conditions[] = "write_ups.category_id = :category_id";
                }
                if ($language) {
                    $conditions[] = "write_ups.language = :language";
                }
                if ($search) {
                    $conditions[] = "write_ups.title LIKE :search";  // Search filter on problem title
                }

                if (count($conditions) > 0) {
                    $query .= " WHERE " . implode(" AND ", $conditions);
                }
                $query .= " ORDER BY write_ups.date_created DESC";

                $stmt = $pdo->prepare($query);
                if ($category_id) {
                    $stmt->bindParam(':category_id', $category_id, PDO::PARAM_INT);
                }
                if ($language) {
                    $stmt->bindParam(':language', $language, PDO::PARAM_STR);
                }
                if ($search) {
                    $searchTerm = "%" . $search . "%";  // Add wildcard for partial matching
                    $stmt->bindParam(':search', $searchTerm, PDO::PARAM_STR);
                }
                $stmt->execute();
                $write_ups = $stmt->fetchAll(PDO::FETCH_ASSOC);

                $counter = 1; // Start the numbering at 1

                foreach ($write_ups as $write_up) {
                    echo '<li>';
                    echo '<span class="problem-number">' . $counter++ . '.</span> ';  // Display the number and increment the counter
                    echo '<a href="view_writeup.php?id=' . $write_up['id'] . '">' . htmlspecialchars($write_up['title']) . '</a>';
                    echo ' <span class="category">(' . htmlspecialchars($write_up['category_name']) . ')</span>';

                    // Display the language (show "C++" instead of "cpp")
                    $language_display = $write_up['language'];
                    if ($language_display === 'cpp') {
                        $language_display = 'C++';
                    }
                    echo ' <span class="language">[' . htmlspecialchars($language_display) . ']</span>';

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
                                echo ' <a href="../delete_writeup.php?id=' . $write_up['id'] . '" class="delete-button">Delete</a>';
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
    <footer onclick="window.location.href='/games/index.php'">
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
