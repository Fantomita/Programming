#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int> Position;

void parseInput(const vector<string>& grid, vector<tuple<int, int, char>>& antennas)
{
    for (int i = 0; i < grid.size(); ++i)
        for (int j = 0; j < grid[i].size(); ++j)
            if (grid[i][j] != '.')
                antennas.push_back({i, j, grid[i][j]});
}

void calculateAntinodes(const vector<Position>& positions, int gridWidth, int gridHeight, set<Position>& antinodes)
{
    for (size_t i = 0; i < positions.size(); ++i)
    {
        for (size_t j = i + 1; j < positions.size(); ++j)
        {
            int x1, y1, x2, y2;
            tie(x1, y1) = positions[i];
            tie(x2, y2) = positions[j];

            // Try extended line in both directions
            for (int k = -gridHeight; k < gridHeight; ++k)
            {
                // Calculate point on the line
                int x = x1 + k * (x2 - x1);
                int y = y1 + k * (y2 - y1);

                // Check if point is within grid bounds
                if (x >= 0 && x < gridHeight && y >= 0 && y < gridWidth)
                {
                    // Check if point is different from the known antenna positions
                    bool isAntenna = false;
                    for (const auto& pos : positions)
                    {
                        if (get<0>(pos) == x && get<1>(pos) == y)
                        {
                            isAntenna = true;
                            break;
                        }
                    }

                    // If it's a valid grid point, add to antinodes
                    antinodes.insert({x, y});
                }
            }
        }
    }
}

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    vector<string> grid;
    string line;
    while (getline(cin, line))
    {
        grid.push_back(line);
    }

    int gridWidth = grid[0].size();
    int gridHeight = grid.size();

    vector<tuple<int, int, char>> antennas;
    parseInput(grid, antennas);

    unordered_map<char, vector<Position>> frequencyGroups;
    for (auto& antenna : antennas)
    {
        int x, y;
        char frequency;
        tie(x, y, frequency) = antenna;
        frequencyGroups[frequency].push_back({x, y});
    }

    set<Position> antinodes;

    for (auto& [frequency, positions] : frequencyGroups)
    {
        // Only process groups with at least 2 antennas
        if (positions.size() >= 2)
        {
            calculateAntinodes(positions, gridWidth, gridHeight, antinodes);
        }
    }

    cout << antinodes.size() << endl;

    return 0;
}