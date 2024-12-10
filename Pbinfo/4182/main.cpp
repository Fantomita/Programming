#include <bits/stdc++.h>
using namespace std;

void secventa(int &n)
{
    int m = 0, p = 1;
    while (n > 9)
    {
        int secv = n % 100;
        if (secv == 22)
        {
            m = 20 * p + m;
            n /= 100;
            p *= 100;
        }
        else
        {
            m = (n % 10) * p + m;
            n /= 10;
            p *= 10;
        }
    }
    n = n * p + m;
}

int main()
{
    int n = 202233228;
    secventa(n);
    cout << n << ' ';
    

    return 0;
}