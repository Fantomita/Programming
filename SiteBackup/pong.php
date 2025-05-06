<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pong Game</title>
    <link rel="stylesheet" href="pong.css">
</head>
<body>
    <div class="game-container">
        <h1>Pong Game</h1>
        <div id="score">Player: 0 | AI: 0</div>
        <canvas id="pongGame"></canvas>
        <button id="restartButton">Restart</button>
        <button id="mainMenuButton">Main Menu</button>
    </div>
    <link rel="stylesheet" href="../../styles/main.css">
    <script src="pong.js"></script>
</body>
</html>
