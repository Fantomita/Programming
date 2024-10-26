#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

signed main()
{
    ifstream cin("podm.in");
    ofstream cout("podm.out");

    int n;
    cin >> n;

    vector<int> d(n + 5);
    vector<vector<int>> dp(n + 5, vector<int>(n + 5, LONG_LONG_MAX));

    for (int i = 0; i <= n; ++i)
        cin >> d[i];

    for (int i = 1; i <= n; ++i)
    {
        dp[i][i] = 0;
        if (i > 1)
            dp[i][i + 1] = d[i - 1] * d[i] * d[i + 1];
    }

    for (int len = 2; len <= n; ++len)
    {
        for (int i = 1; i <= n - len + 1; ++i)
        {
            int j = i + len - 1;
            for (int k = i; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j]);
            }
        }
    }

    cout << dp[1][n] << '\n';

    return 0;
}