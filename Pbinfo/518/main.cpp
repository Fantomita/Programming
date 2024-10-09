#include <iostream>
using namespace std;

void citire()
{
    int n, x, p, u, pmax, umax, maxv = 0;
    pmax = umax = p = u = -1;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        if (x == 0)
        {
            if (p == -1)
                p = i;
            u = i;
        }
        else
            if (p != -1)
            {
                if (u - p + 1 > maxv)
                    pmax = p, umax = u, maxv = u - p + 1, p = -1;
                else
                    p = -1;
            }
    }
    if (p != -1 && u - p + 1 > maxv)
                pmax = p, umax = u, maxv = u - p + 1, p = -1;
    cout << pmax << " " << umax;
}

int main()
{
    citire();
    return 0;
}
