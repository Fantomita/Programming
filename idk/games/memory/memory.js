let currentDifficulty = 'easy'; // Default difficulty
const gameBoard = document.getElementById('game-board');
const difficultySelection = document.getElementById('difficulty-selection');
const gameScreen = document.getElementById('game-screen');

// Expanded symbol collections with more variety
const symbolThemes = {
    animals: [
        '🐱', '🐶', '🐻', '🦁', '🐵', '🐧', '🦄', '🐯', 
        '🦊', '🐰', '🐨', '🐼', '🐮', '🐷', '🐸', '🐒', 
        '🦝', '🐻‍❄️', '🦘', '🦓', '🦌', '🦚', '🐿️', 
        '🦫', '🦥', '🦦', '🦔', '🦨', '🦡', '🐾', '🐤'
    ],
    fruits: [
        '🍎', '🍌', '🍇', '🍓', '🍊', '🍋', '🍉', '🍍', 
        '🥝', '🍒', '🥭', '🍈', '🍏', '🍐', '🍑', '🥥', 
        '🫐', '🍆', '🌽', '🥦', '🥒', '🥕', '🧄', '🍠', 
        '🥔', '🌶️', '🧅', '🍍', '🥬', '🥗', '🍤', '🥖'
    ],
    emojis: [
        '😀', '😎', '🤩', '🥳', '🤔', '😴', '🤪', '😍', 
        '🤯', '😱', '🤢', '🤓', '😇', '🥸', '🤬', '😈', 
        '🤠', '🤡', '🤤', '😵', '😂', '🤫', '🤨', '🧐', 
        '🤭', '🤪', '😳', '🥵', '🥶', '😇', '🤖', '👻'
    ],
    letters: [
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
        'Y', 'Z', '1', '2', '3', '4', '5', '6'
    ],
    sports: [
        '⚽', '🏀', '🏈', '⚾', '🏉', '🥏', '🏓', '🏸', 
        '🏒', '🏹', '🥊', '🛹', '🏄', '🚲', '🏂', '🏃', 
        '🤽', '🏊', '🤺', '🏇', '🥌', '🏄‍♀️', '🏋️', '🤾', 
        '⛷️', '🏌️', '🤼', '🚵', '🏍️', '🏎️', '🧘', '🎾'
    ],
    tech: [
        '💻', '📱', '🖥️', '🖨️', '⌨️', '🖱️', '📷', '🎮', 
        '⌚', '🚁', '📡', '🛰️', '💾', '🔋', '📲', '💿', 
        '🖲️', '💽', '📠', '🎙️', '🎚️', '🔬', '🔭', '📻', 
        '🗜️', '💳', '⚡', '🔌', '☎️', '🖨️', '📞', '📺'
    ],
    symbols: [
        '♠️', '♣️', '♥️', '♦️', '☀️', '✨', '🌈', '🌙', 
        '⭐', '✳️', '❇️', '✴️', '💮', '💯', '🔆', '🌞', 
        '🌝', '🌍', '🌎', '🌏', '🌐', '🌑', '🌒', '🌓', 
        '🌔', '🌕', '🌖', '🌗', '🌘', '🌜', '🌛', '🌚'
    ]
};
 

function selectRandomThemes(difficulty) {
    const allThemes = Object.keys(symbolThemes);
    let themeCount, requiredUniqueSymbols;

    switch(difficulty) {
        case 'easy':
            themeCount = 2;
            requiredUniqueSymbols = 8;
            break;
        case 'medium':
            themeCount = 3;
            requiredUniqueSymbols = 18;  // Changed from 16 to 18 for 6x6 grid
            break;
        case 'hard':
            themeCount = 4;
            requiredUniqueSymbols = 32;
            break;
    }

    // Randomly select unique themes
    let selectedThemes = [];
    let cardSymbols = [];

    while (selectedThemes.length < themeCount) {
        const randomTheme = allThemes[Math.floor(Math.random() * allThemes.length)];
        if (!selectedThemes.includes(randomTheme)) {
            selectedThemes.push(randomTheme);
        }
    }

    // Collect symbols from selected themes, ensuring unique symbols
    selectedThemes.forEach(theme => {
        // Shuffle the theme's symbols and take only what we need
        const shuffledThemeSymbols = shuffle([...symbolThemes[theme]])
            .slice(0, Math.ceil(requiredUniqueSymbols / themeCount));
        cardSymbols.push(...shuffledThemeSymbols);
    });

    // If we don't have enough symbols, shuffle and trim
    cardSymbols = shuffle(cardSymbols).slice(0, requiredUniqueSymbols);

    return { cardSymbols, selectedThemes };
}

// Start the game based on difficulty
function startGame(difficulty) {
    currentDifficulty = difficulty;
    difficultySelection.style.display = 'none'; // Hide difficulty selection
    gameScreen.style.display = 'block'; // Show the game board

    createBoard();
}

// Create the game board based on selected difficulty
function createBoard() {
    let gridSize;

    // Determine grid size based on difficulty
    if (currentDifficulty === 'easy') {
        gridSize = { rows: 4, cols: 4 };
    } else if (currentDifficulty === 'medium') {
        gridSize = { rows: 6, cols: 6 };
    } else if (currentDifficulty === 'hard') {
        gridSize = { rows: 8, cols: 8 };
    }

    // Get random themes and symbols
    const { cardSymbols, selectedThemes } = selectRandomThemes(currentDifficulty);

    // Ensure we have enough cards to fill the grid
    const cards = [...cardSymbols, ...cardSymbols]; 
    const totalCards = gridSize.rows * gridSize.cols;
    const shuffledCards = shuffle(cards.slice(0, totalCards)); 

    // Clear the board
    gameBoard.innerHTML = '';

    // Dynamically set grid template
    gameBoard.style.gridTemplateColumns = `repeat(${gridSize.cols}, 1fr)`; 
    gameBoard.style.gridTemplateRows = `repeat(${gridSize.rows}, 1fr)`; 

    // Create card elements
    shuffledCards.forEach((symbol) => {
        const card = createCard(symbol);
        gameBoard.appendChild(card);
    });

    // Add game logic
    setupGameLogic();

    // Display current themes
    displayThemes(selectedThemes);
}

// Display selected themes
function displayThemes(themes) {
    const themeDisplay = document.getElementById('theme-display');
    if (!themeDisplay) {
        const display = document.createElement('div');
        display.id = 'theme-display';
        display.style.textAlign = 'center';
        display.style.marginBottom = '10px';
        display.style.color = '#ff6347';
        gameScreen.insertBefore(display, gameBoard);
    }

    document.getElementById('theme-display').textContent = 
        `Themes: ${themes.join(', ')}`;
}

// Shuffle an array
function shuffle(array) {
    for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
    return array;
}

// Create a single card element
function createCard(symbol) {
    const card = document.createElement('div');
    card.classList.add('card');

    const cardInner = document.createElement('div');
    cardInner.classList.add('card-inner');

    const cardFront = document.createElement('div');
    cardFront.classList.add('card-front');

    const cardBack = document.createElement('div');
    cardBack.classList.add('card-back');
    cardBack.textContent = symbol;

    cardInner.appendChild(cardFront);
    cardInner.appendChild(cardBack);
    card.appendChild(cardInner);

    return card;
}

// Setup game logic for matching cards
function setupGameLogic() {
    const cards = document.querySelectorAll('.card');
    let flippedCards = [];
    let matchedPairs = 0;
    let canFlip = true;

    cards.forEach(card => {
        card.addEventListener('click', () => {
            // Prevent flipping if already flipped or game is paused
            if (!canFlip || card.classList.contains('matched') || card.classList.contains('flipped')) return;

            // Flip the card
            card.classList.add('flipped');
            flippedCards.push(card);

            // Check for match when two cards are flipped
            if (flippedCards.length === 2) {
                canFlip = false;
                const [card1, card2] = flippedCards;
                const symbol1 = card1.querySelector('.card-back').textContent;
                const symbol2 = card2.querySelector('.card-back').textContent;

                if (symbol1 === symbol2) {
                    // Match found
                    card1.classList.add('matched');
                    card2.classList.add('matched');
                    matchedPairs++;

                    // Check if game is complete
                    if (matchedPairs === (cards.length / 2)) {
                        setTimeout(() => {
                            alert('Congratulations! You won the game!');
                        }, 500);
                    }
                } else {
                    // No match, flip back after a delay
                    setTimeout(() => {
                        card1.classList.remove('flipped');
                        card2.classList.remove('flipped');
                    }, 1000);
                }

                // Reset flipped cards
                setTimeout(() => {
                    flippedCards = [];
                    canFlip = true;
                }, 1000);
            }
        });
    });
}

// Add event listener for window resize to recreate board
window.addEventListener('resize', () => {
    if (gameScreen.style.display !== 'none') {
        createBoard();
    }
});

// Difficulty selection buttons
document.getElementById('easy').addEventListener('click', () => startGame('easy'));
document.getElementById('medium').addEventListener('click', () => startGame('medium'));
document.getElementById('hard').addEventListener('click', () => startGame('hard'));

document.getElementById('backButton').addEventListener('click', () => {
    gameScreen.style.display = 'none'; // Hide the game board
    difficultySelection.style.display = 'flex'; // Show the difficulty selection
    difficultySelection.style.justifyContent = 'center'; // Ensures it stays centered vertically
});

// Main menu redirection
document.getElementById('mainMenuButton').addEventListener('click', () => {
    window.location.href = '../index.php'; // Redirect to main menu
});
 