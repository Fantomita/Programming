#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> originalArea;
int n, m, guardX, guardY;
int loopCount = 0;

const pair<int, int> directions[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isInside(int x, int y)
{
    return (x < n && y < m && x >= 0 && y >= 0);
}

bool simulateGuardPath(vector<vector<int>> &area, int startX, int startY)
{
    int facingDirection = 0;
    int currentX = startX, currentY = startY;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<tuple<int, int, int>> path;

    while (true)
    {
        visited[currentX][currentY] = true;
        path.push_back({currentX, currentY, facingDirection});

        int dx = directions[facingDirection].first;
        int dy = directions[facingDirection].second;

        int newX = currentX + dx;
        int newY = currentY + dy;

        if (!isInside(newX, newY))
            break;

        if (area[newX][newY] == -1)
        {
            facingDirection = (facingDirection + 1) % 4;
            continue;
        }

        currentX = newX;
        currentY = newY;

        for (int i = 0; i < path.size() - 1; i++)
        {
            if (get<0>(path[i]) == currentX &&
                get<1>(path[i]) == currentY &&
                get<2>(path[i]) == facingDirection)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    string line;
    while (getline(cin, line))
    {
        originalArea.push_back(vector<int>(line.size()));
        m = line.size();
        for (int j = 0; j < line.size(); ++j)
        {
            if (line[j] == '.')
                originalArea[n][j] = 0;
            else if (line[j] == '#')
                originalArea[n][j] = -1;
            else if (line[j] == '^')
            {
                guardX = n;
                guardY = j;
            }
        }
        n++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (originalArea[i][j] == -1 || (i == guardX && j == guardY))
                continue;

            vector<vector<int>> testArea = originalArea;
            testArea[i][j] = -1;

            if (simulateGuardPath(testArea, guardX, guardY))
            {
                loopCount++;
            }
        }
    }

    cout << loopCount << '\n';

    return 0;
}