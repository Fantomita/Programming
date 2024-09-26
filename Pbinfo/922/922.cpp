#include <iostream>
#include <cmath>
using namespace std;

struct punct
{
    int x, y;
    float d;
}a[101];

int main()
{
    int n, nr = 0;
    float dmax = 0;
    
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y;

        a[i].d = sqrt(a[i].x * a[i].x + a[i].y * a[i].y);

        if (a[i].d > dmax)
            dmax = a[i].d, nr = 1;
        else if (a[i].d == dmax)
            nr++;
    }

    cout << dmax << ' ' << nr;

    return 0;
}
