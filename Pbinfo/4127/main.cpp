//#include <iostream>
#include <fstream>

using namespace std;

ifstream cin("siruri.in");
ofstream cout("siruri.out");

unsigned long long eliminare(unsigned long long x, bool &ok)
{
    unsigned long long m = 0, p = 1, n;
    int v[10] = {}, nr = 1;
    n = x;
    ok = false;
    while(n > 9)
    {
        p = p * 10;
        n = n / 10;
        nr++;
    }
    n = x;
    while(p)
    {
        if(v[(n / p) % 10] == 0)
        {
            m = m * 10 + (n / p) % 10;
            v[(n / p) % 10] = 1;
            nr--;
        }
        p = p / 10;
    }
    if(nr == 0)
        ok = true;
    return m;
}

int nrcif(unsigned long long x)
{
    int nr = 0;
    do
    {
        nr++;
        x = x / 10;
    }while(x);
    return nr;
}
int main()
{
    unsigned long long x, a[100001], y, t, p;
    int i = 2, n, c, nr = 1, k = 0, nrc, maxv = 0, nrm = 0;
    bool ok;
    cin >> c >> n >> x;
    if(x == eliminare(x, ok))
        k++;
    while(i <= n)
    {
        cin >> y;
        if(y == eliminare(y, ok))
            k++;
        i++;
        t = y;
        p = 1;
        while(t > 9)
        {
            t = t / 10;
            p = p * 10;
        }
        p = p * 10;
        x = eliminare(x, ok);
        if(x % 10 != t)
        {
            a[nr++] = x;
            x = y;
        }
        else
        {
            x = x * p + y;
            a[nr] = eliminare(x, ok);
        }
    }
    n = nr;
    if(x == y)
        a[nr] = eliminare(x, ok);
    for(i = 1; i <= n; i++)
    {
        nrc = nrcif(a[i]);
            if(nrc > maxv)
            {
                maxv = nrc;
                nrm = 1;
            }
            else
                if(nrc == maxv)
                    nrm++;
    }
    if(c == 1)
        cout << k;
    else if(c == 2)
        cout << nr;
    else
        cout << maxv << " " << nrm;
    return 0;
}
