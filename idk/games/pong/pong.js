const canvas = document.getElementById('pongGame');

const ctx = canvas.getContext('2d');

canvas.width = 400;

canvas.height = 300;

const paddleWidth = 8;

const paddleHeight = 60;

let player = {
    x: 20,
    y: (canvas.height - paddleHeight) / 2,
    width: paddleWidth,
    height: paddleHeight,
    speed: 8
};

let ai = {
    x: canvas.width - paddleWidth - 20,
    y: (canvas.height - paddleHeight) / 2,
    width: paddleWidth,
    height: paddleHeight,
    speed: 5,
    reactionDelay: 6
};

let ball = {
    x: canvas.width / 2,
    y: canvas.height / 2,
    radius: 6,
    speedX: 1,
    speedY: 1
};

let playerScore = 0;

let aiScore = 0;

let ballResetting = false;

let touchStartY = null;

let touchMoveY = null;

function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);

    ctx.fillStyle = '#58a6ff';

    ctx.fillRect(player.x, player.y, player.width, player.height);

    ctx.fillRect(ai.x, ai.y, ai.width, ai.height);

    ctx.beginPath();

    ctx.arc(ball.x, ball.y, ball.radius, 0, Math.PI * 2);

    ctx.fillStyle = '#ff6347';

    ctx.fill();

    ctx.closePath();

    if (ballResetting) {
        return;
    }

    ball.x += ball.speedX;

    ball.y += ball.speedY;

    if (ball.y - ball.radius <= 0 || ball.y + ball.radius >= canvas.height) {
        ball.speedY = -ball.speedY;
    }

    if (ball.x - ball.radius <= 0) {
        if (ball.y > player.y && ball.y < player.y + player.height) {
            ball.speedX = -ball.speedX;
        } else {
            aiScore++;

            resetBall();
        }
    }

    if (ball.x + ball.radius >= canvas.width) {
        if (ball.y > ai.y && ball.y < ai.y + ai.height) {
            ball.speedX = -ball.speedX;
        } else {
            playerScore++;

            resetBall();
        }
    }

    if (
        ball.x - ball.radius <= player.x + player.width &&
        ball.y > player.y &&
        ball.y < player.y + player.height
    ) {
        ball.speedX = -ball.speedX;
    }

    if (
        ball.x + ball.radius >= ai.x &&
        ball.y > ai.y &&
        ball.y < ai.y + ai.height
    ) {
        ball.speedX = -ball.speedX;
    }

    if (ai.reactionDelay > 0) {
        ai.reactionDelay--;
    } else {
        if (ball.y < ai.y + ai.height / 2) {
            ai.y -= ai.speed;
        } else if (ball.y > ai.y + ai.height / 2) {
            ai.y += ai.speed;
        }

        ai.y = Math.max(0, Math.min(ai.y, canvas.height - ai.height));

        ai.reactionDelay = 5;
    }

    // Touch controls

    if (touchMoveY !== null) {
        const touchDelta = touchMoveY - touchStartY;

        player.y += touchDelta * 0.5; // Adjust sensitivity as needed

        player.y = Math.max(0, Math.min(player.y, canvas.height - player.height));

        touchStartY = touchMoveY;
    }
}

function resetBall() {
    ballResetting = true;

    setTimeout(function () {
        ball.x = canvas.width / 2;

        ball.y = canvas.height / 2;

        ball.speedX = 2 * (Math.random() < 0.5 ? 1 : -1);

        ball.speedY = 2 * (Math.random() < 0.5 ? 1 : -1);

        ballResetting = false;

        updateScore();
    }, 500);
}

function movePlayer(event) {
    if (event.key === 'ArrowUp' && player.y > 0) {
        player.y -= player.speed;
    }

    if (event.key === 'ArrowDown' && player.y + player.height < canvas.height) {
        player.y += player.speed;
    }
}

document.getElementById('restartButton').addEventListener('click', restartGame);

function restartGame() {
    playerScore = 0;

    aiScore = 0;

    player.y = (canvas.height - paddleHeight) / 2;

    ai.y = (canvas.height - paddleHeight) / 2;

    ball.x = canvas.width / 2;

    ball.y = canvas.height / 2;

    ball.speedX = 1.5;

    ball.speedY = 1.5;

    updateScore();
}

function updateScore() {
    document.getElementById(
        'score'
    ).textContent = `Player: ${playerScore} | AI: ${aiScore}`;
}

document.getElementById('mainMenuButton').addEventListener('click', () => {
    window.location.href = '/index.php';
});

document.addEventListener('keydown', movePlayer);

canvas.addEventListener('touchstart', (e) => {
    touchStartY = e.touches[0].clientY;
});

canvas.addEventListener('touchmove', (e) => {
    e.preventDefault(); // Add this line to prevent default touch behavior
    touchMoveY = e.touches[0].clientY;
});

canvas.addEventListener('touchend', () => {
    touchStartY = null;

    touchMoveY = null;
});

let gameInterval = setInterval(function () {
    draw();
}, 1000 / 60);