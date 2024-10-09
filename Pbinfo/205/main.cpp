#include <fstream>
#include <cmath>
using namespace std;

ifstream cin("shuffle.in");
ofstream cout("shuffle.out");

int n, st[10], k, a[10], poz[10], viz[10], ok;

void sortare()
{
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
                swap(poz[i], poz[j]);
            }
}

void back(int k)
{
    if (k == n + 1)
    {
         ok = 1;
         for (int i = 1; i <= n; ++i)
            cout << a[st[i]] << ' ';
         cout << '\n';
    }
    else
        for (int i = 1; i <= n; ++i)
            if (!viz[i])
            {
                st[k] = i;
                viz[i] = 1;
                if (k == 1 || abs(poz[st[k - 1]] - poz[st[k]]) > 1)
                    back(k + 1);
                viz[i] = 0;
            }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        poz[i] = i;
    }
    sortare();
    back(1);
    if (!ok)
        cout << "nu exista";
    return 0;
}
