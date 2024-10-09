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
    int i, j, t, ok = 0, b = 0;
    for (i = 1; i <= n - k && b == 0; i++)
    {
        for (j = i + 1; j <= n && b == 0; j++)
        {
            ok = 1;
            //cout << i << " " << j << '\n';
            for (t = 1; t <= k && ok; ++t)
                if(a[i + t - 1] != a[j + t - 1])
                    ok = 0;
            if (ok)
            {
                cout << i << " " << j;
                b = 1;
            }
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
