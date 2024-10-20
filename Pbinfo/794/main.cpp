#include <iostream>

using namespace std;

int main()
{
    int n, a[26][26], i, j, x, y, d;

    cin >> n;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            cin >> a[i][j];

    for (d = 1; d <= n; ++d)
    {
        if (d % 2 == 0)
        {
            for (i = d; i >= 1; --i)
                cout << a[i][d - i + 1] << ' ';
        }
        else
        {
            for (i = 1; i <= d; ++i)
                cout << a[i][d - i + 1] << ' ';
        }
    }

    for (d = 1; d < n; ++d)
    {
        if (n % 2 == 0)
        {
            if (d % 2 == 0)
            {
                for (i = n; i > d; --i)
                    cout << a[i][n - i + d + 1] << ' ';
            }
            else
            {
                for (i = d + 1; i <= n; ++i)
                    cout << a[i][n - i + d + 1] << ' ';
            }
        }
        else 
            if (d % 2)
            {
                for (i = n; i > d; --i)
                    cout << a[i][n - i + d + 1] << ' ';
            }
            else
            {
                for (i = d + 1; i <= n; ++i)
                    cout << a[i][n - i + d + 1] << ' ';
            }
    }

    return 0;
}
