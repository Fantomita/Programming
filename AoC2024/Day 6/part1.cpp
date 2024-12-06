#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> area;
int n, m, guardX, guardY;
int facingDirection = 0;
int visitedCells;

const pair<int, int> directions[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isInside(int x, int y)
{
    return (x < n && y < m && x >= 0 && y >= 0);
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
                area[n][i] = 0;
            else if (line[i] == '#')
                area[n][i] = -1;
            else if (line[i] == '^')
            {
                //area[n][i] = 1;
                guardX = n;
                guardY = i;
            }
        }
        n++;
    }

    // cout << guardX << ' ' << guardY << "\n\n";

    while (1)
    {
        int dx = directions[facingDirection].first;
        int dy = directions[facingDirection].second;

        int newX = guardX + dx;
        int newY = guardY + dy;

        if (!isInside(newX, newY))
            break;

        if (area[newX][newY] == 0)
        {
            area[newX][newY] = 1;
            visitedCells++;

            guardX = newX;
            guardY = newY;
        }
        else if (area[newX][newY] == 1)
        {
            guardX = newX;
            guardY = newY;
        }
        else
            facingDirection = (facingDirection + 1) % 4;

        //cout << guardX << ' ' << guardY << '\n';
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j)
    //         cout << area[i][j] << ' ';
    //     cout << '\n';
    // }

    cout << visitedCells << '\n';

    return 0;
}