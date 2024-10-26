#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int v[501];
int vp[251], vi[251];
int np, ni, n, sp = 1, si;

int fastExp(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main()
{
    int x;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x % 2 == 0)
        {
            sp = sp * 2 + 1;
            si = si * 2;
        }
        else
        {
            ci = sp;
            cp = si;
            sp = sp + si;
            si = ci + 1;

        }
    }

    cout << sp - 1;

    return 0;
}