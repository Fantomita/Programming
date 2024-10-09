#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() 
{
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
    }

    long long total_sum = 0;
    long long suffix_sum = 0;

    for (int dr = n - 1; dr >= 2; --dr) 
    {
        suffix_sum = (suffix_sum + a[dr]) % MOD;
        long long prefix_sum = 0;

        for (int st = dr - 2; st >= 0; --st) 
        {
            prefix_sum = (prefix_sum + a[st + 1]) % MOD;
            long long cost = a[st] * prefix_sum % MOD * a[dr] % MOD;
            total_sum = (total_sum + cost) % MOD;
        }
    }

    cout << total_sum << endl;
    return 0;
}
