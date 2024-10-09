#include <iostream>

using namespace std;

int main()
{
    int n, a[16][16] = {};

    cin >> n;

    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= i; ++j)
        {
            if (i == n)
                a[i][j] = j;
            else if (j <= i)
                a[i][j] = a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
        }

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';

    return 0;
}
