#include <iostream>

using namespace std;

int n, k, st[20], viz[20];

void back(int k)
{
    if ((k - 1) % 2)
    {
        for (int i = 1; i < k; ++i)
            cout << st[i] << ' ';
        cout << '\n';
    }
    if (k <= n)
        for (int i = 1; i <= n; ++i)
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
}