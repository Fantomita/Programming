#include <iostream>

using namespace std;

int main()
{
    int n, a[21][21];
    long long maxv = -1e9;
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
            maxv = max(maxv, 1LL * a[i][i] * a[j][n - j + 1]);
        }
    }

    cout << maxv;

    return 0;
}