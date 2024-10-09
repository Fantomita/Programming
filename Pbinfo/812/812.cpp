#include <iostream>

using namespace std;

int main()
{
    int n, a[16][16] = {};

    cin >> n;

    for (int i = n; i >= 1; --i)
        a[i][1] = 1,
        a[n][i] = i;

    for (int i = n - 1; i >= 1; --i)
        for (int j = 2; j <= n; ++j)
            a[i][j] = a[i][j - 1] + a[i + 1][j];
    
    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; cout << a[i][j] << ' ', ++j);

    return 0;
}
