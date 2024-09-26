#include <iostream>
#include <algorithm>

using namespace std;

int n, a[15], st[15], viz[15], minv = 1000000005, maxv = -1, pozmin, pozmax;

void back(int k)
{
    if (k == n + 1)
    {
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
                if ((k != pozmin && k != pozmax) || ((k == pozmin && st[k] && a[st[k]] == minv) || (k == pozmax && st[k] && a[st[k]] == maxv)))
                    back(k + 1);
                viz[i] = 0;
            }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];

        if (a[i] < minv)
        {
            minv = a[i];
            pozmin = i;
        }
        if (a[i] > maxv)
        {
            maxv = a[i];
            pozmax = i;
        }
    }

    sort(a + 1, a + n + 1);

    back(1);
    return 0;
}
