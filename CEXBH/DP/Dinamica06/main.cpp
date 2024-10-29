#include <bits/stdc++.h>
using namespace std;

#define MOD 123457

int fastExp(int a, int b)
{
    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    cout << (2 * 1LL * fastExp(3, n - 1)) % MOD << endl;

    return 0;
}