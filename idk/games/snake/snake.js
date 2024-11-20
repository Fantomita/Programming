const canvas = document.getElementById('snakeGame');
const ctx = canvas.getContext('2d');

// Set canvas size
canvas.width = 300;
canvas.height = 300;

// Snake settings
const box = 10;
let score = 0;

let snake = [{ x: 5 * box, y: 5 * box }];
let direction = 'RIGHT';

// Food settings
let food = spawnFood();

// Get the score element from the HTML
const scoreElement = document.getElementById('score');

// Game functions
function draw() {
    ctx.fillStyle = "#1e1e1e";
    ctx.fillRect(0, 0, canvas.width, canvas.height);

    for (let i = 0; i < snake.length; i++) {
        ctx.fillStyle = i === 0 ? "#58a6ff" : "#eaeaea";
        ctx.fillRect(snake[i].x, snake[i].y, box, box);
    }

    ctx.fillStyle = "#ff0000";
    ctx.fillRect(food.x, food.y, box, box);

    let snakeX = snake[0].x;
    let snakeY = snake[0].y;

    if (direction === 'RIGHT') snakeX += box;
    if (direction === 'LEFT') snakeX -= box;
    if (direction === 'UP') snakeY -= box;
    if (direction === 'DOWN') snakeY += box;

    if (snakeX === food.x && snakeY === food.y) {
        score++;
        food = spawnFood();
    } else {
        snake.pop();
    }

    const newHead = { x: snakeX, y: snakeY };

    if (collision(newHead)) {
        clearInterval(game);
    }

    snake.unshift(newHead);

    // Update the score outside of the canvas
    scoreElement.textContent = "Score: " + score;
}

function collision(head) {
    if (head.x < 0 || head.x >= canvas.width || head.y < 0 || head.y >= canvas.height) {
        return true;
    }
    for (let i = 0; i < snake.length; i++) {
        if (head.x === snake[i].x && head.y === snake[i].y) {
            return true;
        }
    }
    return false;
}

function spawnFood() {
    let validPosition = false;
    let newFoodPosition;

    while (!validPosition) {
        newFoodPosition = {
            x: Math.floor(Math.random() * (canvas.width / box)) * box,
            y: Math.floor(Math.random() * (canvas.height / box)) * box
        };

        validPosition = !snake.some(segment => segment.x === newFoodPosition.x && segment.y === newFoodPosition.y);
    }

    return newFoodPosition;
}

// Control the snake with keyboard events (WASD and Arrow Keys)
document.addEventListener("keydown", directionControl);

function directionControl(event) {
    if (event.key === 'ArrowLeft' || event.key === 'a') direction = direction !== 'RIGHT' ? 'LEFT' : direction;
    if (event.key === 'ArrowUp' || event.key === 'w') direction = direction !== 'DOWN' ? 'UP' : direction;
    if (event.key === 'ArrowRight' || event.key === 'd') direction = direction !== 'LEFT' ? 'RIGHT' : direction;
    if (event.key === 'ArrowDown' || event.key === 's') direction = direction !== 'UP' ? 'DOWN' : direction;
}

// Restart game
document.getElementById('restartButton').addEventListener('click', restartGame);

function restartGame() {
    snake = [{ x: 5 * box, y: 5 * box }];
    score = 0;
    direction = 'RIGHT';
    food = spawnFood();
    scoreElement.textContent = "Score: " + score;
    game = setInterval(draw, 100);
}

document.getElementById('mainMenuButton').addEventListener('click', () => {
    window.location.href = '/index.php';
});

// Initialize the game
let game = setInterval(draw, 100);
