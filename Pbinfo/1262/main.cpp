#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin ("subsecv.in");
ofstream cout ("subsecv.out");

int n, a[10005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        long long s = 0;

        for (int j = i; j <= n; ++j)
        {
            s += a[j];

            if (s % n == 0)
            {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }

    return 0;
}
