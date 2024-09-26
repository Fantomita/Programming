#include <bits/stdc++.h>

using namespace std;

ifstream fin("bipartit2.in");
ofstream fout("bipartit2.out");

int n, m, adj[105][105];

void bfs(int start)
{
    int q[105] = {}, viz[105] = {}, st = 1, dr = 1;
    bool ok = 1;

    q[dr++] = start;
    viz[start] = 1;

    while(st < dr)
    {
        int nod = q[st];
        st++;
        for (int i = 1; i <= n; ++i)
            if (adj[nod][i] && !viz[i])
            {
                if (viz[nod] == 1)
                    viz[i] = 2;
                else
                    viz[i] = 1;
                q[dr++] = i;
            }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            if (viz[i] == 1 && viz[j] == 1 && adj[i][j])
                ok = 0;
            if (viz[i] == 2 && viz[j] == 2 && adj[i][j])
                ok = 0;
        }

    if (ok)
    {
        fout << "DA\n";
        for (int i = 1; i <= n; ++i)
            if (viz[i] == 1)
                fout << i << ' ';
        fout << '\n';
        for (int i = 1; i <= n; ++i)
            if (viz[i] == 2)
                fout << i << ' ';
    }
    else
        fout << "NU\n";
}

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        fin >> x >> y;
        adj[x][y] = adj[y][x] = 1;
    }

    bfs(1);


    return 0;
}
