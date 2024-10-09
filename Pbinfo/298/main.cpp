#include <iostream>
using namespace std;

ifstream cin("sumsec.in");
ofstream cout("sumsec.out");

bool prim(int x)
{
    if (x < 2 || x % 2 == 0 && x != 2)
        return 0;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
        return 0;
    return 1;
}

int main()
{
    int a[1001], n, s = 0, p = 0, u = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (prim(a[i]))
        {
            if (p == 0)
                p = i;
            u = i;
        }
    }
    for (int i = p; i <= u; ++i)
        s += a[i];
    cout << s;
    return 0;
}
