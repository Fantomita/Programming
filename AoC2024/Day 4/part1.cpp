#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    ifstream cin ("input.in");
    ofstream cout ("output.out");

    vector<string> grid;
    string line;
    while (getline(cin, line))
        grid.push_back(line);

    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                int x = i, y = j, k;
                for (k = 0; k < 4; k++)
                {
                    if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != "XMAS"[k])
                        break;

                    x += dx[dir];
                    y += dy[dir];
                }
                if (k == 4)
                    count++;
            }
        }
    }

    cout << count << '\n';

    return 0;
}