#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream in("zona3.in");
ofstream out("zona3.out");

const int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };

int n, m, a[105][105], zone[5005];
queue<pair<int, int>> q;

bool inmat(int i, int j)
{
    if (i < 1 || i > n || j < 1 || j > m)
        return false;
    return true;
}

void lee(int i, int j, int &nr)
{
    q.push(make_pair(i, j));
    a[i][j] = nr;
    zone[nr]++;
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        for (int k = 0; k < 4; ++k)
        {
            int xx = x + di[k], yy = y + dj[k];
            if (a[xx][yy] == 1 && inmat(xx, yy))
            {
                q.push(make_pair(xx, yy));
                zone[nr]++;
                a[xx][yy] = nr;
            }
        }
        q.pop();
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            int nr = 0;
            if (a[i][j] == 1)
            {
                lee(i, j, nr);
                nr++;
            }
        }

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= m; ++j)
            cout << zone[a[i][j]] << ' ';

    return 0;
}
