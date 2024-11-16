#include <bits/stdc++.h>
using namespace std;

int n, a[20][20];
int dp[20][1 << 18];

int main()
{
    ifstream cin("teamwork.in");
    ofstream cout("teamwork.out");

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    for (int i = 0; i < n; ++i)
        dp[0][1 << i] = a[0][i];

    for (int i = 1; i < n; ++i)
        for (int mask = 1; mask < (1 << n); ++mask)
            for (int j = 0; j < n; ++j)
                if ((mask & (1 << j)) == 0)
                    dp[i][mask | (1 << j)] = max(dp[i][mask | (1 << j)], dp[i - 1][mask] + a[i][j]);

    cout << dp[n - 1][(1 << n) - 1];

    return 0;
}