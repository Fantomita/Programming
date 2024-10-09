#include <iostream>
using namespace std;

void citire()
{
   int n, x, p, nr = 0, maxv = 0;
   cin >> n;
   for (int i = 1; i <= n; ++i)
   {
        cin >> x;
        p = 1;
        while (p < x)
            p *= 2;
        if (x && (x == p - 1 || x == 1))
            nr++;
        else
        {
            if (nr > maxv)
                maxv = nr;
            nr = 0;
        }
   }
   if (nr > maxv)
                maxv = nr;
   cout << maxv;
}

int main()
{
    citire();
    return 0;
}
