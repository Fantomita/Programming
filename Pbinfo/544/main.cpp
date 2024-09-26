#include <bits/stdc++.h>

using namespace std;

#define cin fin
#define cout fout

ifstream fin("partial.in");
ofstream fout("partial.out");

int n, adj[205][205], k, newAdj[205][205], viz[205];

void dfs(int nod)
{
    viz[nod] = 1;
    for (int i = 1; i <= n; ++i)
        if (adj[nod][i] && !viz[i])
        {
            newAdj[nod][i] = newAdj[i][nod] = 1;
            dfs(i);
        }
}

int main()
{
    cin >> n;
    int x, y;
    while (cin >> x >> y)
    {
        adj[x][y] = adj[y][x] = 1;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (adj[i][j])
                k++;

    k /= 2;

    dfs(1);

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (cnt != k && adj[i][j] && !newAdj[i][j])
            {
                adj[i][j] = adj[j][i] = 0;
                cnt++;
            }
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
