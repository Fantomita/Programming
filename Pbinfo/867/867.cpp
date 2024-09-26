#include <iostream>

using namespace std;

int main()
{
    int n, x, y, a, q[100005] = {}, st = 1, dr = 0, f[10005] = {};

    cin >> n >> a >> x >> y;

    q[++dr] = a;

    while (st <= dr)
    {
        a = q[st];
        f[a] = 1;

        if (a + x <= n && !f[a + x])
        {
            q[++dr] = a + x;
            f[a + x] = 1;
        }
        if (a + y <= n && !f[a + y])
        {
            q[++dr] = a + y;
            f[a + y] = 1;
        }

        st++;
    }

    for (int i = 0; i <= 10000; ++i)
        if (f[i])
            cout << i << ' ';
}