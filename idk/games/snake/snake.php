<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Snake Game</title>
    <link rel="stylesheet" href="snake.css">
</head>
<body>
    <div class="game-container">
        <h1>Snake Game</h1>
        <div id="score">Score: 0</div>  <!-- Score displayed here -->
        <canvas id="snakeGame"></canvas>
        <button id="restartButton">Restart</button>
        <button id="mainMenuButton">Main Menu</button>  <!-- Main Menu Button -->
    </div>
	<link rel="stylesheet" href="../../styles/main.css">
    <script src="snake.js"></script>
</body>
</html>
