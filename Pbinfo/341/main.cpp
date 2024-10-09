#include <fstream>
#include <vector>
using namespace std;

ifstream cin("bomboane.in");
ofstream cout("bomboane.out");

int n, s, a[1005], mv_from[1005], mv_to[1005], mv_nb[1005], k;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        s += a[i];
    }

    if (s % n)
    {
        cout << -1;

        return 0;
    }
    else
    {
        int m = s / n;

        while(1)
        {
            int maxv = 1, minv = 1;
            for (int i = 2; i <= n; ++i)
            {
                if (a[i] > a[maxv])
                    maxv = i;
                if (a[i] < a[minv])
                    minv = i;
            }

            if (maxv == minv)
                break;

            mv_from[++k] = maxv;
            mv_to[k] = minv;
            mv_nb[k] = m - a[minv];
            a[maxv] -= (m - a[minv]);
            a[minv] = m;
        }
    }

    cout << k << '\n';
    for (int i = 1; i <= k; ++i)
        cout << mv_from[i] << ' ' << mv_to[i] << ' ' << mv_nb[i] << '\n';

    return 0;
}
