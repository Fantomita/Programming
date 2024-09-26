#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("sirpie.in");
ofstream cout("sirpie.out");

int st[14], viz[14], n, a[14];

int cmmdc(int x, int y)
{
    while(y > 0)
    {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

void tipar(int k)
{
    for (int i = 1; i <= k; ++i)
        cout << a[st[i]] << ' ';
    cout << '\n';
}

void back(int k)
{
    if (k == n + 1)
        tipar(k - 1);
    else
        for (int i = 1; i <= n; ++i)
            if(!viz[i])
            {
                st[k] = i;
                viz[i] = 1;
                if (k == 1 || (k > 1 && cmmdc(a[st[k - 1]], a[st[k]]) == 1))
                    back(k + 1);
                viz[i] = 0;
            }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    back(1);

    return 0;
}
