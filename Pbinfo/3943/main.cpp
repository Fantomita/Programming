#include <iostream>
#include <cmath>
using namespace std;

int n, st[40], k, poz[40], viz[40], ok;

bool pp(int a, int b)
{
    int sq = sqrt(a + b);
    return (sq * sq == a + b);
}

void back(int k)
{
    if(!ok)
        if (k == n + 1)
        {
             if (pp(st[1], st[n]))
             {
                 ok = 1;
                 for (int i = 1; i <= n; ++i)
                    cout << st[i] << ' ';
                 cout << '\n';
             }
        }
        else
            for (int i = 1; i <= n; ++i)
                if (!viz[i])
                {
                    st[k] = i;
                    viz[i] = 1;
                    if (k == 1 || pp(st[k], st[k - 1]))
                        back(k + 1);
                    viz[i] = 0;
                }
}

int main()
{
    cin >> n;
    if (n < 32)
        cout << "nu exista";
    else
    {
        back(1);
        if (!ok)
            cout << "nu exista";
    }

    return 0;
}
