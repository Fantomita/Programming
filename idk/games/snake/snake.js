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

// Touch control variables
let touchStartX = null;
let touchStartY = null;
let lastDirection = direction;
const SWIPE_THRESHOLD = 10; // Reduced from 20 for more sensitivity

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
    scoreElement.textContent = "Score: " + score;
}

function collision(head) {
    if (head.x < 0 || head.x >= canvas.width || head.y < 0 || head.y >= canvas.height) {
        return true;
    }

    for (let i = 1; i < snake.length; i++) {
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

        validPosition = !snake.some(segment => 
            segment.x === newFoodPosition.x && segment.y === newFoodPosition.y
        );
    }

    return newFoodPosition;
}

// Keyboard controls
function directionControl(event) {
    const key = event.key.toLowerCase();
    
    if ((key === 'arrowleft' || key === 'a') && direction !== 'RIGHT') {
        direction = 'LEFT';
    }
    if ((key === 'arrowup' || key === 'w') && direction !== 'DOWN') {
        direction = 'UP';
    }
    if ((key === 'arrowright' || key === 'd') && direction !== 'LEFT') {
        direction = 'RIGHT';
    }
    if ((key === 'arrowdown' || key === 's') && direction !== 'UP') {
        direction = 'DOWN';
    }
}

// Enhanced touch controls
function handleTouchStart(event) {
    event.preventDefault();
    const touch = event.touches[0];
    touchStartX = touch.clientX - canvas.offsetLeft;
    touchStartY = touch.clientY - canvas.offsetTop;
    lastDirection = direction;
}

function handleTouchMove(event) {
    if (!touchStartX || !touchStartY) return;

    event.preventDefault();
    const touch = event.touches[0];
    const currentX = touch.clientX - canvas.offsetLeft;
    const currentY = touch.clientY - canvas.offsetTop;

    const deltaX = currentX - touchStartX;
    const deltaY = currentY - touchStartY;

    // Only change direction if the swipe is significant enough
    if (Math.abs(deltaX) > SWIPE_THRESHOLD || Math.abs(deltaY) > SWIPE_THRESHOLD) {
        // Determine if the swipe is more horizontal or vertical
        if (Math.abs(deltaX) > Math.abs(deltaY)) {
            // Horizontal swipe
            if (deltaX > 0 && direction !== 'LEFT') {
                direction = 'RIGHT';
            } else if (deltaX < 0 && direction !== 'RIGHT') {
                direction = 'LEFT';
            }
        } else {
            // Vertical swipe
            if (deltaY > 0 && direction !== 'UP') {
                direction = 'DOWN';
            } else if (deltaY < 0 && direction !== 'DOWN') {
                direction = 'UP';
            }
        }

        // Update start positions only if direction changed
        if (direction !== lastDirection) {
            touchStartX = currentX;
            touchStartY = currentY;
            lastDirection = direction;
        }
    }
}

function handleTouchEnd(event) {
    event.preventDefault();
    touchStartX = null;
    touchStartY = null;
}

// Restart game function
function restartGame() {
    snake = [{ x: 5 * box, y: 5 * box }];
    score = 0;
    direction = 'RIGHT';
    food = spawnFood();
    scoreElement.textContent = "Score: " + score;
    clearInterval(game);
    game = setInterval(draw, 80); // Slightly faster game speed
}

// Event Listeners
document.addEventListener("keydown", directionControl);
canvas.addEventListener('touchstart', handleTouchStart, { passive: false });
canvas.addEventListener('touchmove', handleTouchMove, { passive: false });
canvas.addEventListener('touchend', handleTouchEnd, { passive: false });
document.getElementById('restartButton').addEventListener('click', restartGame);
document.getElementById('mainMenuButton').addEventListener('click', () => {
    window.location.href = '/index.php';
});

// Initialize the game
let game = setInterval(draw, 80);