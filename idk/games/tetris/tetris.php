<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tetris Game</title>
    <link rel="stylesheet" href="tetris.css">
</head>
<body>
    <div class="game-container">
        <h1>Tetris Game</h1>
        <div id="score">Score: 0</div>
        <canvas id="tetrisGame"></canvas>
        <button id="restartButton">Restart</button>
        <button id="mainMenuButton">Main Menu</button>
    </div>
	<link rel="stylesheet" href="../../styles/main.css">
    <script src="tetris.js"></script>
</body>
</html>
