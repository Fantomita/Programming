#include <iostream>

using namespace std;

int main()
{
    int n, m, x, y, a[105][105] = {};

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        a[x][y] = 1;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                    if (i != j && j != k && k != i && (a[i][j] || a[j][i])
                        && (a[j][k] || a[k][j]) && (a[k][i] || a[i][k]))
                            cout << i << ' ' << j << ' ' << k << '\n';

    return 0;
}
