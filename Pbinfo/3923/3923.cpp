#include <iostream>

using namespace std;

int n, m, st[30], viz[30];

void back(int k)
{
    if (k == m + 1)
    {
        for (int i = 1; i <= m; ++i)
            cout << char(st[i] + 'A' - 1);
        cout << '\n';
    }
    else
        for (int i = 1; i <= n; ++i)
            if (!viz[i])
            {
                st[k] = i;
                viz[i] = 1;
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