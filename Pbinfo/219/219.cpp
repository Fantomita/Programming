#include <iostream>
using namespace std;

int main()
{
    int a[25][25] = {}, n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; ++i && cout << '\n')
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1 && j == 1)
                a[i][j] = n * m;
            if (j > 1)
                a[i][j] = a[i][j - 1] - 1;
            if (j == 1 && i > 1)
                a[i][j] = a[i - 1][m] - 1;

            cout << a[i][j] << ' ';
        }

    return 0;
}