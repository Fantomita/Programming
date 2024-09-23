#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_XOR = 1024;

int main() {
    int N, X;
    cin >> N >> X;

    if (N >= MAX_XOR)
    {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> dp(MAX_XOR, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= N; ++i) 
    {
        vector<int> new_dp = dp;
        for (int x = 0; x < MAX_XOR; ++x) 
        {
            int new_xor = x ^ i;
            new_dp[new_xor] = (new_dp[new_xor] + dp[x]) % MOD;
        }
        dp = new_dp;
    }

    cout << dp[X] << endl;

    return 0;
}
