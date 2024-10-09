#include <iostream>
#include <bitset>
using namespace std;

bitset<100000>f;

int main()
{
    int x, ok = 0, n, a = 0, b = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        if(x <= 999)
            f[x] = 1;
    }
    for (int i = 999; i >= 100; --i)
        if (!f[i] && ok < 2)
        {
            if (ok == 0)
                b = i;
            else
                a = i;
            ++ok;
        }
    if (ok != 2)
        cout << "NU EXISTA";
    else
        cout << a << " " << b;
    return 0;
}
