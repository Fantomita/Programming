#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define FROM_FILE
#define inf 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef FROM_FILE
    freopen("submatrix.in", "r", stdin);
    freopen("submatrix.out", "w", stdout);
    #endif // FROM_FILE

    int n, maxDim = -inf;
    vector<vector<int>> a, dp;

    cin >> n;
    a = dp = vector<vector<int>>(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];

            if (i == 1 || j == 1)
                dp[i][j] = a[i][j];
            else if (a[i][j] == 1)
            {
                dp[i][j] = min({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]}) + 1;
            }

            maxDim = max(maxDim, dp[i][j]);
        }
    }

    cout << maxDim << '\n';

    return 0;
}
