#include <iostream>

using namespace std;

int n, st[10], viz[10];

int valid(int k)
{
    int nrp = 0;
    for (int i = 1; i <= k; ++i)
        if (st[i] % 2 == 0)
            nrp++;
    if (nrp <= n - nrp)
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
                cout << st[i];
            cout << '\n';
        }
    }
    else
        for (int i = 0; i <= 9; ++i)
            if (!viz[i])
            {
                st[k] = i;
                viz[i] = 1;
                if ((k == 1 && i != 0) || k > 1)
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