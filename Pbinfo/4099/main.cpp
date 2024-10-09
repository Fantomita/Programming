#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

ifstream in("transport.in");
ofstream out("transport.out");

int t, n, c, x[200005], d[200005], p2[1005];

void citire()
{
    in >> t >> n >> c;
    for (int i = 1; i <= n; ++i)
        in >> x[i] >> d[i];
    p2[0] = 1;
    for (int i = 1; i <= 1004; ++i)
        p2[i] = (p2[i - 1] * 2) % MOD;
    /*for (int i = 1; i <= 1004; i++)
        cout << p2[i] << " ";*/
}

void cer1()
{
    int nr = 0, sc;
    for (int i = 1; i < n; ++i)
    {
        for (int j = n; j > i; --j)
        {
            sc = c * (x[j] - x[i]) - (d[i] + d[j]);
            //cout << i << " " << j << " " << sc << '\n';
            if (sc == 0)
                nr = (nr + 1) % MOD;
        }
    }
    out << nr;
}

void cer2()
{
    long long nr = 0, sc;
    for (int i = n; i > 1; --i)
    {
        for (int j = n; j > i; --j)
        {
            sc = c * (x[j] - x[i]) - (d[i] + d[j]);
            //cout << i << " " << j << " " << sc << '\n';
            if (sc == 0)
                nr =(nr + p2[j - i - 1]) % MOD;
        }
    }
    out << nr;
}

int main()
{
    citire();
    if (t == 1)
        cer1();
    else
        cer2();
    return 0;
}
