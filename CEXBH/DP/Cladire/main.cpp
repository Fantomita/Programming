#include <bits/stdc++.h>
using namespace std;

#define MOD 9901

vector<vector<int>> dp(1001, vector<int>(1001, -1));

int countWays(int n, int m)
{
    //cout << "Called for: " << n << " " << m << "\n";

    if (n == 1 || m == 1)
        return 1;

    if (dp[n][m] != -1)
        return dp[n][m];

    dp[n][m] = (countWays(n - 1, m) + countWays(n, m - 1)) % MOD;
    return dp[n][m];
}

int main()
{
    ifstream cin("cladire.in");
    ofstream cout("cladire.out");

    int n, m;
    cin >> n >> m;

    cout << countWays(n, m) << "\n";

    return 0;
}