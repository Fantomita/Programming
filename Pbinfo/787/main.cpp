#include <iostream>

using namespace std;

int main()
{
    int n, a[105][105];
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i + j < n + 1)
            {
                int aux = a[n - j + 1][n - i + 1];
                a[n - j + 1][n - i + 1] = a[i][j];
                a[i][j] = aux;
            }

            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
