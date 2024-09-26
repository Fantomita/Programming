#include <iostream>
using namespace std;

void citire(int& n, int& k, int a[])
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

void secv(int n, int k, int a[])
{
    int i, j, t, nr = 0, ok = 0, b = 0;
    nr = n / k;
    for (i = 1; i <= n - nr && b == 0; i += nr)
    {
        for (j = i + nr; j <= n && b == 0; j += nr)
        {
            ok = 1;
            //cout << i << " " << j << '\n';
            for (t = 1; t <= nr && ok; ++t)
                if(a[i + t - 1] != a[j + t - 1])
                    ok = 0;
            if (ok)
                cout << i / nr + 1 << " " << j / nr + 1, b  = 1;
        }
    }
    if (b == 0)
        cout << "NU";
}

int main()
{
    int n, k, a[1005];
    citire(n, k, a);
    secv(n, k, a);
    return 0;
}
