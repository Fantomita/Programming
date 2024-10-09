#include <bits/stdc++.h>

using namespace std;

ifstream fin("abx.in");
ofstream fout("abx.out");

#define int long long int
int n, m;

inline int expFaraRapida(int a, int n) 
{
    int aux = 1;
    for(int i=1; i<=n; i++) 
    {
        if(aux > m / a) return 2e18;
        aux *= a;
    }
    return aux;
}

inline int bazaOptima(int x, int exp) 
{
    int st = 1, dr = m, sol = -1;
    while(st <= dr) 
    {
        int mid = (st + dr) / 2;
        if(expFaraRapida(mid, exp) <= x) sol = max(sol, mid), st = mid + 1;
        else dr = mid - 1;
    }
    return sol;
}

inline void solve(int x) 
{
    int rez = 0;
    for(int exp=2; exp<=60; exp++) 
    {
        int baza = bazaOptima(x, exp);
        int a = expFaraRapida(baza, exp), b = expFaraRapida(baza + 1, exp);
        int dif1 = abs(x - a), dif2 = abs(x - b);
        if(dif1 <= dif2 || b > m) 
        {
            if(dif1 <= abs(x - rez)) rez = a;
        }
        else if(dif2 < abs(x - rez)) rez = b;
    }
    fout << rez << '\n';
}

signed main()
{
    fin >> n >> m;
    for (int i = 1; i <= n; ++i) 
    {
        int x; 
        fin >> x;
        solve(x);
    }

    return 0;
}