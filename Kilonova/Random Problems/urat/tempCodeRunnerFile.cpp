#include <bits/stdc++.h>

#define FROMFILE

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    #ifdef FROMFILE
    freopen("urat.in", "r", stdin);
    freopen("urat.out", "w", stdout);
    #endif

    int n;

    cin >> n;
    cout << 1LL * n * (n - 1) / 2 << '\n' << n << '\n' << n << '\n';

    return 0;
}