#include <iostream>
#include <cstring>

using namespace std;

int n, st[30], viz[30];

int valid(int k)
{
    int nrv = 0;
    for (int i = 1; i <= k; ++i)
        if (strchr("AEIOU", char(st[i] + 'A' - 1)))
            nrv++;
    if (nrv <= n - nrv)
        return 0;
    return 1;
}

void back(int k)
{
    if (k == n + 1)
    {
        if (valid(n))
        {
            for (int i = 1; i <= n; ++i)
                cout << char(st[i] + 'A' - 1);
            cout << '\n';
        }
    }
    else
        for (int i = 1; i <= 26; ++i)
            if (!viz[i])
            {
                st[k] = i;
                viz[i] = 1;
                if (k == 1 || k > 1 && st[k - 1] < st[k])
                back(k + 1);
                viz[i] = 0;
            }
}

int main()
{
    cin >> n;
    back(1);

    return 0;
}