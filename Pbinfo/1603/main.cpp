#include <fstream>

using namespace std;

ifstream cin("ccmax.in");
ofstream cout("ccmax.out");

int viz[101], c[101], maxv, nr;

void bfs(int n, int a[101][101], int vf)
{
    int p, u, k;

    p = u = 1;
    c[p] = vf;
    viz[vf] = 1;

    while (p <= u)
    {
        for (k = 1; k <= n; ++k)
            if (!viz[k] && a[c[p]][k])
            {
                c[++u] = k;
                viz[k] = 1;
            }
        p++;
    }

    if (u > maxv)
        maxv = u, nr = 1;
    else if (u == maxv)
        nr++;
}

int main()
{
    int n, x, y, a[101][101] = {}, i = 1;

    cin >> n;
    while(cin >> x >> y)
        a[x][y] = a[y][x] = 1;

    do
    {
        bfs(n, a, i);

        for (i = 1; i <= n && viz[i]; ++i);
    }while(i <= n);

    cout << maxv << ' ' << nr;

    return 0;
}
