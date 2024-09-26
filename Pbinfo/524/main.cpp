#include <iostream>
using namespace std;

int main()
{
    int n, a[1005], p, u, pmax, umax, maxv = 0, i;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n - maxv; i++)
    {
        p = i, u = n;
        while (a[u] != a[p] && u > p)
            u--;
        if (u - p + 1 > maxv)
            pmax = p, umax = u, maxv = u - p + 1;
    }
    cout << pmax << " " << umax;
    return 0;
}
