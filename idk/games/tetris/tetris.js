const canvas = document.getElementById('tetrisGame');
const ctx = canvas.getContext('2d');

canvas.width = 300;
canvas.height = 600;

const ROWS = 20;
const COLUMNS = 10;
const BLOCK_SIZE = 30;

const tetrominoes = [
    { shape: [[1, 1, 1, 1]], color: '#FF6347' }, // I - Red
    { shape: [[1, 1, 1], [0, 0, 1]], color: '#1E90FF' }, // L - Blue
    { shape: [[1, 1, 1], [1, 0, 0]], color: '#32CD32' }, // J - Green
    { shape: [[1, 1], [1, 1]], color: '#FFD700' }, // O - Yellow
    { shape: [[0, 1, 1], [1, 1, 0]], color: '#FF1493' }, // S - Pink
    { shape: [[1, 1, 0], [0, 1, 1]], color: '#DAA520' }, // Z - Goldenrod
    { shape: [[1, 1, 1], [0, 1, 0]], color: '#8A2BE2' }, // T - Purple
];

let board = Array.from({ length: ROWS }, () => Array(COLUMNS).fill(0));
let currentTetromino = generateTetromino();
let currentPos = { x: 3, y: 0 };
let score = 0;
let isGameOver = false;

function draw() {
    ctx.fillStyle = '#1e1e1e';
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    drawTetromino(currentTetromino, currentPos.x, currentPos.y);

    for (let row = 0; row < ROWS; row++) {
        for (let col = 0; col < COLUMNS; col++) {
            if (board[row][col] !== 0) {
                ctx.fillStyle = board[row][col];
                ctx.fillRect(col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
            }
        }
    }

    document.getElementById('score').textContent = `Score: ${score}`;
}

function drawTetromino(tetromino, x, y) {
    for (let row = 0; row < tetromino.shape.length; row++) {
        for (let col = 0; col < tetromino.shape[row].length; col++) {
            if (tetromino.shape[row][col]) {
                ctx.fillStyle = tetromino.color;
                ctx.fillRect((x + col) * BLOCK_SIZE, (y + row) * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
            }
        }
    }
}

function moveTetromino(dx, dy) {
    if (isGameOver) return;

    currentPos.x += dx;
    currentPos.y += dy;
    if (collides()) {
        currentPos.x -= dx;
        currentPos.y -= dy;
        if (dy > 0) {
            placeTetromino();
            currentTetromino = generateTetromino();
            currentPos = { x: 3, y: 0 };
            if (collides()) {
                gameOver();
            }
        }
    }
}

function rotateTetromino() {
    if (isGameOver) return;

    const rotated = currentTetromino.shape[0].map((_, index) =>
        currentTetromino.shape.map(row => row[index])
    ).reverse();
    const tempTetromino = { ...currentTetromino, shape: rotated };
    const tempPos = { ...currentPos };

    currentTetromino = tempTetromino;
    if (collides()) {
        currentTetromino = { ...tempTetromino, shape: currentTetromino.shape.reverse() };
    }
}

function collides() {
    for (let row = 0; row < currentTetromino.shape.length; row++) {
        for (let col = 0; col < currentTetromino.shape[row].length; col++) {
            if (currentTetromino.shape[row][col]) {
                const newX = currentPos.x + col;
                const newY = currentPos.y + row;
                if (newX < 0 || newX >= COLUMNS || newY >= ROWS || board[newY] && board[newY][newX]) {
                    return true;
                }
            }
        }
    }
    return false;
}

function placeTetromino() {
    for (let row = 0; row < currentTetromino.shape.length; row++) {
        for (let col = 0; col < currentTetromino.shape[row].length; col++) {
            if (currentTetromino.shape[row][col]) {
                board[currentPos.y + row][currentPos.x + col] = currentTetromino.color;
            }
        }
    }
    clearFullRows();
}

function clearFullRows() {
    for (let row = ROWS - 1; row >= 0; row--) {
        if (board[row].every(cell => cell !== 0)) {
            board.splice(row, 1);
            board.unshift(Array(COLUMNS).fill(0));
            score += 100;
        }
    }
}

function generateTetromino() {
    const randomIndex = Math.floor(Math.random() * tetrominoes.length);
    return tetrominoes[randomIndex];
}

function handleTouchStart(event) {
    event.preventDefault(); // Prevent scrolling on touch start
    if (isGameOver) return;

    const touchX = event.touches[0].clientX;
    const touchY = event.touches[0].clientY;

    if (touchY < canvas.height / 2) {
        rotateTetromino();
    } else {
        if (touchX < canvas.width / 2) {
            moveTetromino(-1, 0);
        } else {
            moveTetromino(1, 0);
        }
    }
}

let lastTouchX = null;

function handleTouchMove(event) {
    event.preventDefault(); // Prevent scrolling on touch move

    if (isGameOver) return;

    const touchX = event.touches[0].clientX;

    if (lastTouchX !== null) {
        if (touchX > lastTouchX) {
            moveTetromino(1, 0);
        } else if (touchX < lastTouchX) {
            moveTetromino(-1, 0);
        }
    }

    lastTouchX = touchX;
}

document.addEventListener('keydown', (event) => {
    if (isGameOver) return;

    if (event.key === 'ArrowLeft') moveTetromino(-1, 0);
    if (event.key === 'ArrowRight') moveTetromino(1, 0);
    if (event.key === 'ArrowDown') moveTetromino(0, 1);
    if (event.key === 'ArrowUp') rotateTetromino();
});

canvas.addEventListener('touchstart', handleTouchStart);
canvas.addEventListener('touchmove', handleTouchMove);

function gameLoop() {
    if (!isGameOver) {
        moveTetromino(0, 1);
        draw();
    }
}

function resetGame() {
    board = Array.from({ length: ROWS }, () => Array(COLUMNS).fill(0));
    score = 0;
    currentTetromino = generateTetromino();
    currentPos = { x: 3, y: 0 };
    isGameOver = false;
    clearInterval(gameInterval);
    gameInterval = setInterval(gameLoop, 500);
}

function gameOver() {
    isGameOver = true;
    alert('Game Over!');
}

let gameInterval = setInterval(gameLoop, 500);

document.getElementById('restartButton').addEventListener('click', resetGame);
document.getElementById('mainMenuButton').addEventListener('click', () => {
    window.location.href = '/index.php';
});