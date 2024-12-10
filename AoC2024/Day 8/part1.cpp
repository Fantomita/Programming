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
    for (auto i = 0; i < positions.size(); ++i)
    {
        for (auto j = i + 1; j < positions.size(); ++j)
        {
            int x1, y1, x2, y2;
            tie(x1, y1) = positions[i];
            tie(x2, y2) = positions[j];

            int dx = x2 - x1;
            int dy = y2 - y1;

            int ax1 = x1 - dx, ay1 = y1 - dy;
            int ax2 = x2 + dx, ay2 = y2 + dy;

            if (ax1 >= 0 && ax1 < gridHeight && ay1 >= 0 && ay1 < gridWidth)
                antinodes.insert({ax1, ay1});
            if (ax2 >= 0 && ax2 < gridHeight && ay2 >= 0 && ay2 < gridWidth)
                antinodes.insert({ax2, ay2});
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
        calculateAntinodes(positions, gridWidth, gridHeight, antinodes);
    }

    // for (auto& antenna : antennas)
    // {
    //     int x, y;
    //     tie(x, y, ignore) = antenna;
    //     antinodes.erase({x, y});
    // }

    cout << antinodes.size() << endl;


    return 0;
}