#include <bits/stdc++.h>
using namespace std;

#define NMAX 1005

struct Position
{
    int x, y;
};

int m, n, k, p, xc, yc;
vector<Position> knights;
vector<vector<int>> dist;

const vector<pair<int, int>> knightMoves =
{
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
};

bool isValid(int x, int y)
{
    return x >= 1 && x <= m && y >= 1 && y <= n;
}

void bfs()
{
    dist.assign(m + 1, vector<int>(n + 1, -1));
    queue<pair<int, int>> q;
    dist[xc][yc] = 0;
    q.push({xc, yc});

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (const auto& move : knightMoves)
        {
            int nx = cx + move.first;
            int ny = cy + move.second;

            if (isValid(nx, ny) && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ifstream cin("camelot.in");
    ofstream cout("camelot.out");

    cin >> p >> m >> n >> k;
    cin >> xc >> yc;

    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        knights.push_back({x, y});
    }

    bfs();

    if (p == 1)
    {
        int minMoves = INT_MAX;
        for (const auto& knight : knights)
        {
            if (dist[knight.x][knight.y] != -1)
                minMoves = min(minMoves, dist[knight.x][knight.y]);
        }
        cout << minMoves << '\n';
    }
    else if (p == 2)
    {
        int maxMoves = 0;
        for (const auto& knight : knights)
        {
            if (dist[knight.x][knight.y] != -1)
                maxMoves = max(maxMoves, dist[knight.x][knight.y]);
        }
        cout << maxMoves << '\n';
    }

    return 0;
}
