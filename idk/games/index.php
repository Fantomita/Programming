<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Games Hub</title>
    <link rel="stylesheet" href="../../styles/main.css">
</head>
<body>
    <header>
        <h1>Games Hub</h1>
    </header>
    <div class="container">
        <h2>Choose a Game:</h2>
        <div style="display: flex; flex-wrap: wrap; gap: 20px;">
            <a href="/games/snake/snake.php" class="game-button">Snake</a>
            <a href="/games/tetris/tetris.php" class="game-button">Tetris</a>
            <a href="/games/pong/pong.php" class="game-button">Pong</a>
            <a href="/games/memory/memory.php" class="game-button">Memory Game</a>
        </div>
    </div>
    <footer>
        <p>Created by Luncan Vlad-Cosmin &copy; 2024</p>
    </footer>
</body>
</html>
