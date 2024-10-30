#include <bits/stdc++.h>

using namespace std;

int n;

int dp[205][205];

int main()
{
    ifstream cin("sumtri.in");
    ofstream cout("sumtri.out");

    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            cin >> dp[i][j];
        }
    }
    int maxim = 0;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            dp[i][j] = dp[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
            maxim = max(maxim, dp[i][j]);
        }
    }

    cout << maxim << "\n";
}
