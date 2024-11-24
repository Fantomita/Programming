#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, n = 0, m = 0;

    while (cin >> x >> y)
    {
        m++;
        n = max(n, max(x, y));
    }

    cout << m - n + 2;

    return 0;
}