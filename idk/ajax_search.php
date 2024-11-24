<?php
try {
    $pdo = new PDO('sqlite:/var/www/db/problems.db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $category_id = isset($_GET['category_id']) ? $_GET['category_id'] : null;
    $language = isset($_GET['language']) ? $_GET['language'] : null;
    $search = isset($_GET['search']) ? $_GET['search'] : '';

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
        $conditions[] = "write_ups.title LIKE :search";  
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
        $stmt->bindValue(':search', "%$search%", PDO::PARAM_STR);
    }

    $stmt->execute();
    $writeups = $stmt->fetchAll(PDO::FETCH_ASSOC);

    echo json_encode($writeups);
} catch (PDOException $e) {
    echo json_encode([]);
}
