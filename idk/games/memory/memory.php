<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Memory Match Game</title>
    <link rel="stylesheet" href="memory.css">
</head>
<body>
    <div class="game-container">
        <header>
            <h1>Memory Match</h1>
        </header>

        <!-- Difficulty Selection Screen -->
        <div id="difficulty-selection">
            <h2>Select Difficulty</h2>
            <button id="easy">Easy (4x4)</button>
            <button id="medium">Medium (6x6)</button>
            <button id="hard">Hard (8x8)</button>
            <button id="mainMenuButton">Main Menu</button>
        </div>

        <!-- Game Screen -->
        <main id="game-screen" style="display: none;">
            <div id="game-board" class="game-board"></div>

            <!-- Buttons container -->
            <!-- Buttons container -->
            <div class="buttons-container">
                <button id="backButton">Back</button>
            </div>
        </main>
    </div>
    <script src="memory.js"></script>
</body>
</html>