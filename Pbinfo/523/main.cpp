#include <iostream>
using namespace std;

void citire()
{
    int n, x, y, p, u, pmax, umax, maxv = 0;
    pmax = umax = p = u = -1;
    cin >> n >> x;
    for (int i = 2; i <= n; ++i)
    {
        cin >> y;
        if (x == y)
        {
            if (p == -1)
                p = i - 1;
            u = i;
        }
        else
            if (p != -1)
            {
                if (u - p + 1 >= maxv)
                    pmax = p, umax = u, maxv = u - p + 1, p = -1;
                else
                    p = -1;
            }
        x = y;
    }
    if (p != -1 && u - p + 1 >= maxv)
                pmax = p, umax = u, maxv = u - p + 1, p = -1;
    cout << pmax << " " << umax;
}

int main()
{
    citire();
    return 0;
}
