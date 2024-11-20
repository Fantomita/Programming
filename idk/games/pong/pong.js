const canvas = document.getElementById('pongGame');
const ctx = canvas.getContext('2d');

// Set smaller canvas size
canvas.width = 400;
canvas.height = 300;

// Create the paddle
const paddleWidth = 60;  // Smaller width for paddle
const paddleHeight = 8;
let player = {
    x: (canvas.width - paddleWidth) / 2,
    y: canvas.height - paddleHeight - 20,
    width: paddleWidth,
    height: paddleHeight,
    speed: 8  // Adjusted speed
};

let ai = {
    x: (canvas.width - paddleWidth) / 2,
    y: 20,
    width: paddleWidth,
    height: paddleHeight,
    speed: 8,  // Increased AI speed
    reactionDelay: 3  // Reduced reaction delay for quicker AI
};

// Create the ball
let ball = {
    x: canvas.width / 2,
    y: canvas.height / 2,
    radius: 6,  // Slightly smaller ball
    speedX: 1.5,  // Initial small speed
    speedY: 1.5   // Initial small speed
};

let playerScore = 0;
let aiScore = 0;
let ballResetting = false;  // Flag to track when the ball is resetting

// Draw elements on canvas
function draw() {
    // Clear the canvas
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    // Draw the paddles
    ctx.fillStyle = '#58a6ff';
    ctx.fillRect(player.x, player.y, player.width, player.height);  // Player's paddle
    ctx.fillRect(ai.x, ai.y, ai.width, ai.height);  // AI's paddle

    // Draw the ball
    ctx.beginPath();
    ctx.arc(ball.x, ball.y, ball.radius, 0, Math.PI * 2);
    ctx.fillStyle = '#ff6347';
    ctx.fill();
    ctx.closePath();

    // If the ball is resetting, pause its movement
    if (ballResetting) {
        return;
    }

    // Ball movement
    ball.x += ball.speedX;
    ball.y += ball.speedY;

    // Ball collision with the left and right walls
    if (ball.x - ball.radius <= 0 || ball.x + ball.radius >= canvas.width) {
        ball.speedX = -ball.speedX; // Reverse the X direction if the ball hits the wall
    }

    // Ball collision with the top wall (Player scoring)
    if (ball.y - ball.radius <= 0) {
        if (ball.x > ai.x && ball.x < ai.x + ai.width) {
            ball.speedY = -ball.speedY; // If the ball hits the AI paddle, reflect it
        } else {
            playerScore++;  // AI scores when the ball passes the AI's paddle
            resetBall();
        }
    }

    // Ball collision with the bottom wall (AI scoring)
    if (ball.y + ball.radius >= canvas.height) {
        if (ball.x > player.x && ball.x < player.x + player.width) {
            ball.speedY = -ball.speedY; // If the ball hits the player paddle, reflect it
        } else {
            aiScore++;  // Player scores when the ball passes the player's paddle
            resetBall();
        }
    }

    // Ball collision with paddles (for both player and AI)
    if (ball.y - ball.radius <= ai.y + ai.height && ball.x > ai.x && ball.x < ai.x + ai.width) {
        ball.speedY = -ball.speedY;
    }
    if (ball.y + ball.radius >= player.y && ball.x > player.x && ball.x < player.x + player.width) {
        ball.speedY = -ball.speedY;
    }

    // AI Paddle movement (with reaction delay)
    if (ai.reactionDelay > 0) {
        ai.reactionDelay--;  // AI's reaction delay countdown
    } else {
        if (ball.x < ai.x + ai.width / 2) {
            ai.x -= ai.speed;  // Move left
        } else if (ball.x > ai.x + ai.width / 2) {
            ai.x += ai.speed;  // Move right
        }

        // Prevent AI from moving out of bounds
        ai.x = Math.max(0, Math.min(ai.x, canvas.width - ai.width));

        // Reset AI's reaction delay after it moves
        ai.reactionDelay = 5;  // Smaller delay to make it more responsive
    }

    // Player control (using arrow keys)
    document.addEventListener('keydown', movePlayer);
}

// Reset ball to center after scoring
function resetBall() {
    ballResetting = true;  // Indicate that the ball is resetting

    // Reset ball to the center with a non-zero initial speed
    setTimeout(function() {
        ball.x = canvas.width / 2;
        ball.y = canvas.height / 2;

        // Set ball speed to a small, non-zero value (ensure it moves)
        ball.speedX = 2 * (Math.random() < 0.5 ? 1 : -1);  // Small initial speed with direction
        ball.speedY = 2 * (Math.random() < 0.5 ? 1 : -1);  // Small initial speed with direction

        ballResetting = false;  // Allow ball movement to resume
        updateScore();  // Update the score after resetting the ball
    }, 500);  // 500ms delay after scoring
}

// Move the player paddle based on keyboard input
function movePlayer(event) {
    if (event.key === 'ArrowLeft' && player.x > 0) {
        player.x -= player.speed;
    }
    if (event.key === 'ArrowRight' && player.x + player.width < canvas.width) {
        player.x += player.speed;
    }
}

// Restart the game
document.getElementById('restartButton').addEventListener('click', restartGame);

function restartGame() {
    playerScore = 0;
    aiScore = 0;
    player.x = (canvas.width - paddleWidth) / 2;
    ball.x = canvas.width / 2;
    ball.y = canvas.height / 2;
    ball.speedX = 1.5;  // Non-zero ball speed to start
    ball.speedY = 1.5;  // Non-zero ball speed to start
    updateScore();  // Reset the score display
}

// Update the score in the HTML
function updateScore() {
    document.getElementById('score').textContent = `Player: ${playerScore} | AI: ${aiScore}`;
}

// Add event listener for the Main Menu button (similar to snake.js)
document.getElementById('mainMenuButton').addEventListener('click', () => {
    window.location.href = '/index.php'; // Modify the URL to where you want to redirect
});

// Main game loop
let gameInterval = setInterval(function() {
    draw();
}, 1000 / 60);  // 60 FPS
