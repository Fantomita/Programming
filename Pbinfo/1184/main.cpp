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
    freopen("epuras.in", "r", stdin);
    freopen("epuras.out", "w", stdout);
    #endif // FROM_FILE

    int n;
    vector<vector<int>> a, dp;

    cin >> n;
    a = dp = vector<vector<int>>(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    dp[1][1] = a[1][1];
    for (int j = 2; j <= n; ++j)
        dp[1][j] = max({dp[1][j - 1], dp[1][j - 1] + a[1][j]});
    for (int i = 2; i <= n; ++i)
        dp[i][1] = max({dp[i - 1][1], dp[i - 1][1] + a[i][1]});

    for (int i = 2; i <= n; ++i)
        for (int j = 2; j <= n; ++j)
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j] + a[i][j], dp[i][j - 1] + a[i][j]});
    dp[n][n] = max({dp[n - 1][n], dp[n][n - 1]}) + a[n][n];

    cout << dp[n][n];

    return 0;
}
