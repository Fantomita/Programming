#include <iostream>

using namespace std;

int main()
{
    int n, m, a[16][16] = {};

    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= m; ++j)
        {
            if (i % 2)
                a[i][j] = (i - 1) * m + j;
            else
                a[i][j] = i * m - j + 1;

            cout << a[i][j] << ' ';
        }

    return 0;
}
