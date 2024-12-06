#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> area;
int n, m, guardX, guardY;
int facingDirection = 0;

const pair<int, int> directions[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isInside(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

bool simulate(int startX, int startY, int startDirection, vector<vector<int>> &grid)
{
    int x = startX, y = startY, direction = startDirection;
    set<tuple<int, int, int>> seenStates;

    while (true)
    {
        if (seenStates.count({x, y, direction}))
        {
            return true;
        }
        seenStates.insert({x, y, direction});

        int dx = directions[direction].first;
        int dy = directions[direction].second;

        int newX = x + dx;
        int newY = y + dy;

        if (!isInside(newX, newY))
        {
            return false;
        }

        if (grid[newX][newY] == 0)
        {
            x = newX;
            y = newY;
        }
        else if (grid[newX][newY] == -1)
        {
            direction = (direction + 1) % 4;
        }
        else
        {
            x = newX;
            y = newY;
        }
    }
}

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    string line;
    while (getline(cin, line))
    {
        area.push_back(vector<int>(line.size()));
        m = line.size();
        for (int i = 0; i < line.size(); ++i)
        {
            if (line[i] == '.')
            {
                area[n][i] = 0;
            }
            else if (line[i] == '#')
            {
                area[n][i] = -1;
            }
            else if (line[i] == '^')
            {
                guardX = n;
                guardY = i;
            }
        }
        n++;
    }

    set<pair<int, int>> initialPath;
    int x = guardX, y = guardY, direction = facingDirection;

    while (true)
    {
        initialPath.insert({x, y});

        int dx = directions[direction].first;
        int dy = directions[direction].second;

        int newX = x + dx;
        int newY = y + dy;

        if (!isInside(newX, newY))
        {
            break;
        }

        if (area[newX][newY] == 0)
        {
            x = newX;
            y = newY;
        }
        else if (area[newX][newY] == -1)
        {
            direction = (direction + 1) % 4;
        }
        else
        {
            x = newX;
            y = newY;
        }
    }

    int loopCount = 0;

    for (auto [i, j] : initialPath)
    {
        if (!(i == guardX && j == guardY))
        {
            area[i][j] = -1;
            if (simulate(guardX, guardY, facingDirection, area))
            {
                loopCount++;
            }
            area[i][j] = 0;
        }
    }

    cout << loopCount << '\n';
    return 0;
}
