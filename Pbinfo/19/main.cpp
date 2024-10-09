#include <fstream>

using namespace std;

ifstream cin("BFS.in");
ofstream cout("BFS.out");

void bfs(int x, int n, int a[105][105])
{
    int c[105], viz[105] = {}, p, u, k;
    p = u = 1;
    c[p] = x;
    viz[x] = 1;

    while(p <= u)
    {
        for (int k = 1; k <= n; ++k)
            if (a[c[p]][k] && !viz[k])
            {
                u++;
                c[u] = k;
                viz[k] = 1;
            }
        p++;
    }

    for (int i = 1; i <= u; ++i)
        cout << c[i] << ' ';
}

int main()
{
    int n, m, x, a[105][105], i, j;

    cin >> n >> m >> x;
    for (int k = 1; k <= m; ++k)
    {
        cin >> i >> j;
        a[i][j] = a[j][i] = 1;
    }

    bfs(x, n, a);


    return 0;
}
