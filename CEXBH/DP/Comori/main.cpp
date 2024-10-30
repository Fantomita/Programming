#include <bits/stdc++.h>

using namespace std;

int n, m;

int dp[205][205];

int main()
{
    ifstream cin("comori.in");
    ofstream cout("comori.out");

    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> dp[i][j];
        }
    }
    int maxim = 0;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            dp[i][j] = dp[i][j] + max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i - 1][j + 1]));
            maxim = max(maxim, dp[i][j]);
        }
    }

    cout << maxim << "\n";
}