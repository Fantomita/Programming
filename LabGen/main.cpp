#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

// Directions for movement: {dx, dy}
const int directions[4][2] = {
    {0, 2},  // Down
    {0, -2}, // Up
    {2, 0},  // Right
    {-2, 0}  // Left
};

void printMaze(const vector<vector<int>>& maze) {
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Check if the cell is within bounds and surrounded by walls
bool isValid(int x, int y, int width, int height, const vector<vector<int>>& maze) {
    return x > 0 && y > 0 && x < height - 1 && y < width - 1 && maze[x][y] == 1;
}

void generateMaze(int width, int height, vector<vector<int>>& maze) {
    stack<pair<int, int>> backtrackStack; // Stack for backtracking
    int startX = 1, startY = 1;           // Starting point
    maze[startX][startY] = 0;             // Mark start as path

    backtrackStack.push({startX, startY});
    std::random_device rd;    // Seed for randomness
    std::mt19937 rng(rd());   // Mersenne Twister random number generator

    while (!backtrackStack.empty()) {
        auto [x, y] = backtrackStack.top();

        // Shuffle directions to create randomness
        vector<int> dirOrder = {0, 1, 2, 3};
        std::shuffle(dirOrder.begin(), dirOrder.end(), rng);

        bool moved = false;

        for (int i : dirOrder) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            int wallX = x + directions[i][0] / 2;
            int wallY = y + directions[i][1] / 2;

            if (isValid(nx, ny, width, height, maze)) {
                maze[wallX][wallY] = 0; // Remove the wall between
                maze[nx][ny] = 0;      // Mark new cell as path
                backtrackStack.push({nx, ny});
                moved = true;
                break;
            }
        }

        if (!moved) {
            backtrackStack.pop(); // Backtrack if no moves are possible
        }
    }
}

int main() {
    int width, height;
    cout << "Enter maze width and height (both must be odd): ";
    cin >> width >> height;

    // Ensure dimensions are odd for proper maze structure
    if (width % 2 == 0) width++;
    if (height % 2 == 0) height++;

    vector<vector<int>> maze(height, vector<int>(width, 1)); // Initialize maze with walls

    generateMaze(width, height, maze);

    cout << "Generated Maze:" << endl;
    printMaze(maze);

    return 0;
}
