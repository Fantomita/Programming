#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 666013

int fastExp(int a, int b)
{
    int ans = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * a) % MOD;
        }

        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

signed main()
{
    ifstream cin("no_pals.in");
    ofstream cout("no_pals.out");

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            cout << 0 << '\n';
        }
        else
        {
            long long ans = (9 * fastExp (10, i - 1)) % MOD;
            // for (int j = 2; j <= i; ++j)
            // {
            //     ans = (ans * 10) % MOD;
            // }
            
            long long pals = (9 * fastExp(10, (i + 1) / 2 - 1)) % MOD;
            // for (int j = 2; j <= (i + 1) / 2; j++)
            // {
            //     pals = (pals * 10) % MOD;
            // }

            ans = (ans - pals + MOD) % MOD;

            cout << ans << '\n';
        }
    }

    return 0;
}