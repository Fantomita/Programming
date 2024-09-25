#include <fstream>

using namespace std;

ifstream cin("summax.in");
ofstream cout("summax.out");

int a[11][11], n, st[11], viz[11], smax;

void back(int k)
{
    if (k == n + 1)
    {
        int s = 0;
        for (int i = 1; i <= n; ++i)
            s += a[i][st[i]];
        if (s > smax)
            smax = s;
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
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    back(1);
    cout << smax;
    return 0;
}