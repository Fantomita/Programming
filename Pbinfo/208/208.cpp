#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a[21][21], n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; ++i && cout << '\n')
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1 && j == 1)
                a[i][j] = 1;
            if (j > 1)
                a[i][j] = ((int)sqrt(a[i][j - 1]) + 2) * ((int)sqrt(a[i][j - 1]) + 2);
            if (j == 1 && i > 1)
                a[i][j] = ((int)sqrt(a[i - 1][m]) + 2) * ((int)sqrt(a[i - 1][m]) + 2);

            cout << a[i][j] << ' ';
        }
    
    return 0;
}
