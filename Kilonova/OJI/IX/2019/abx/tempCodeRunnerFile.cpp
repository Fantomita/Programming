#include <bits/stdc++.h>

#define int long long int

using namespace std;

ifstream fin("abx.in");
ofstream fout("abx.out");

int n, m;
const int inf = 1e18 + 1;

int exp(int a, int b) 
{
    int rez = 1;
    for(int i = 1; i <= b; i++) 
    {
        if(rez > m/a)
            return inf;
        rez *= a;
    }
    return rez;
}

int findBase(int x, int b) 
{
    int st = 1, dr = m, rez;
    while(st <= dr) 
    {
        int mij = (st + dr) / 2;
        if(exp(mij, b) <= x) 
        {
            rez = mij;
            st = mij + 1;
        } else {
            dr = mij - 1;
        }
    }
    return rez;
}

int solve(int x) 
{
    int rez = 0;
    for(int b = 2; b <= 59; b++) 
    {
        int a = findBase(x, b);
        //cout << b << ' ' << a << ' ' << '\n';
        int r1 = exp(a, b);
        int r2 = exp(a+1, b);
        if(abs(x - r1) <= abs(x - r2) || r2 > m) 
            if(abs(x - r1) <= abs(x - rez))
                rez = r1;
        else 
            if(abs(x - r2) < abs(x - rez))
                rez = r2;
    }
    return rez;
}

signed main() 
{
    fin >> n >> m;

    for (int i = 1; i <= n; ++i) 
    {
        int x;
        fin >> x;
        fout << solve(x) << '\n';
    }

    return 0;
}
