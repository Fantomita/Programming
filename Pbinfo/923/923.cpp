#include <iostream>
using namespace std;

struct fractie
{
    int num, nm;
}f1, f2, f;

int cmmdc(int x, int y)
{
    int r;
    do
    {
        r = x % y;
        x = y;
        y = r;
    } while (r);

    return x;
}

int main()
{
    int dc;

    cin >> f1.num >> f1.nm >> f2.num >> f2.nm;

    if ((float)f1.num / f1.nm > (float)f2.num / f2.nm) 
    {
        f.num = f1.num;
        f.nm = f1.nm; 
    }
    else 
    { 
        f.num = f2.num;
        f.nm = f2.nm; 
    }

    dc = cmmdc(f.num, f.nm);

    cout << f.num / dc << " " << f.nm / dc;

    return 0;
}
