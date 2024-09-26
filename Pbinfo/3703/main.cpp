#include <fstream>
#define MOD 1000000007

using namespace std;

ifstream cin("potter.in");
ofstream cout("potter.out");

int lin, col, t, K, a[2005][2005];

void set_turret(int i, int j)
{
    for (int jj = 1; jj <= col; ++jj)
        a[i][jj] = 1;
    for (int ii = 1; ii <= lin; ++ii)
        a[ii][j] = 1;
}

void read()
{
    cin >> lin >> col >> t >> K;

    int x, y;
    for (int i = 1; i <= t; ++i)
    {
        cin >> x >> y;
        set_turret(x, y);
    }
}

int fast_expo(long long n, long long p)
{
    int r = 1;
    while(p)
    {
        if (p % 2 == 1) r = (1LL * r * n) % MOD;
        n = (1LL * n * n) % MOD;
        p /= 2;
    }
    return r % MOD;
}

int invers_mod(long long n)
{
    return (1LL * fast_expo(n, MOD - 2) % MOD) % MOD;
}

int fact(long long k)
{
    if (k < 2) return 1;
    int s = 1;
    for (int i = 2; i <= k; ++i)
        s = (1LL * s * i % MOD) % MOD;
    return s;
}

int fact_simplf(long long n, long long k)
{
    if (n - k == 1) return n;
    int s = 1;
    for (int i = n - k + 1; i <= n; ++i)
        s = (1LL * s * i % MOD) % MOD;
    return s;
}

int comb(long long n, long long k)
{
    if (n < k) return 0;
    if (n == k) return 1;
    return (1LL * fact(n) % MOD * invers_mod(1LL * fact(n - k) % MOD * fact(k) % MOD) % MOD  + MOD) % MOD;
}

int main()
{
    read();

    int nr = 0;
    for (int i = 1; i <= lin; ++i)
        for (int j = 1; j <= col; ++j)
            if (a[i][j] == 0)
                nr++;

    cout << comb(nr - 1 + K, nr - 1);

    return 0;
}
