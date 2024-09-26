#include <iostream>
using namespace std;

int main()
{
    int a[101][101] = {}, n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] != 1)
                a[i][j] = 2;
            if (abs(i - j) <= k)
                a[i][j] = 1;
            if (j == n - i + 1)
                for (int t = 0; t <= k; ++t)
                    a[i][n - i - t + 1] = a[i + t][n - i + 1] = 1;
                
        }

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; cout << a[i][j] << ' ', ++j);

    return 0;
}
