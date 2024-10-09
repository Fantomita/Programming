#include <iostream>

using namespace std;

int main()
{
    int n, a[26][26], i, j, x, y, d;

    cin >> n;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            cin >> a[j][i];

    for (d = 1; d <= n; ++d)
        if (d % 2 == 0)
        {
            j = d;
            for (i = 1; i <= d; ++i)
                cout << a[i][j--] << ' ';
        }
        else
        {
            i = d;
            for (j = 1; j <= d; ++j)
                cout << a[i--][j] << ' ';
        }

    int k = 2;

    for (; d <= 2 * n - 1; ++d)
        if (d % 2 == 0)
        {
            i = k;
            for (j = n; i <= n; --j, ++i)
                cout << a[i][j] << ' ';
            ++k;
        }
        else
        {
            j = k;
            for (i = n; j <= n; --i, ++j)
                cout << a[i][j] << ' ';
            ++k;
        }

    return 0;
}
