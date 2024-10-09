#include <fstream>

using namespace std;

ifstream cin("dfs.in");
ofstream cout("dfs.out");

int n, a[105][105], viz[105];

void dfs(int x)
{
    viz[x] = 1;

    cout << x << ' ';

    for (int k = 1; k <= n; ++k)
        if (a[x][k] && !viz[k])
            dfs(k);
}

int main()
{
    int m, i, j, k, x;

    cin >> n >> m >> x;

    for (k = 1; k <= m; ++k)
    {
        cin >> i >> j;

        a[i][j] = a[j][i] = 1;
    }

    dfs(x);

    return 0;
}
