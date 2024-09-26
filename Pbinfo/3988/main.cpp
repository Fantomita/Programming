#include <iostream>
#include <algorithm>

using namespace std;

int n, m, viz[15], st[15];

void back(int k)
{
    if (k == n + 1)
    {
        for (int i = 1; i <= n; ++i)
            cout << st[i] << ' ';
        cout << '\n';
    }
    else
        for (int i = 1; i <= n; ++i)
            if (!viz[i])
            {
                st[k] = i;
                viz[i] = 1;
                if (k == 1 || (k > 1 && abs(st[k - 1] - st[k]) <= m))
                    back(k + 1);
                viz[i] = 0;
            }
}

int main()
{
    cin >> n >> m;

    back(1);
    return 0;
}
