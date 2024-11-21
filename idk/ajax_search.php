<?php
header('Content-Type: application/json');

try {
    $pdo = new PDO('sqlite:/var/www/db/problems.db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $search = isset($_GET['search']) ? trim($_GET['search']) : '';
    $category_id = isset($_GET['category_id']) ? $_GET['category_id'] : '';
    $language = isset($_GET['language']) ? $_GET['language'] : '';

    // Adjust the language to 'cpp' for C++ filter selection
    if ($language === 'C++') {
        $language = 'cpp';
    }

    $query = "SELECT write_ups.*, categories.name AS category_name 
              FROM write_ups 
              LEFT JOIN categories ON write_ups.category_id = categories.id";
    $conditions = [];

    if (!empty($search)) {
        $conditions[] = "write_ups.title LIKE :search";
    }
    if (!empty($category_id)) {
        $conditions[] = "write_ups.category_id = :category_id";
    }
    if (!empty($language)) {
        $conditions[] = "write_ups.language = :language";
    }

    if (count($conditions) > 0) {
        $query .= " WHERE " . implode(" AND ", $conditions);
    }
    $query .= " ORDER BY write_ups.date_created DESC";

    $stmt = $pdo->prepare($query);

    if (!empty($search)) {
        $stmt->bindValue(':search', '%' . $search . '%', PDO::PARAM_STR);
    }
    if (!empty($category_id)) {
        $stmt->bindValue(':category_id', $category_id, PDO::PARAM_INT);
    }
    if (!empty($language)) {
        $stmt->bindValue(':language', $language, PDO::PARAM_STR);
    }

    $stmt->execute();
    $write_ups = $stmt->fetchAll(PDO::FETCH_ASSOC);

    echo json_encode($write_ups);
} catch (PDOException $e) {
    echo json_encode(['error' => $e->getMessage()]);
}
