#include <iostream>

using namespace std;

int main()
{
    int n, m, a[21][21];
    
    cin >> n >> m;

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1 && j == 1)
                a[i][j] = 2;
            else if (j == 1)
                a[i][j] = a[i - 1][m] + ((a[i - 1][m] + 2) % 5 == 0 ? 4 : 2);
            else
                a[i][j] = a[i][j - 1] + ((a[i][j - 1] + 2) % 5 == 0 ? 4 : 2);

            cout << a[i][j] << ' ';
        }

    return 0;
}
