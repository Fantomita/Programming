#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[50005], b[50005];
unsigned long long s;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    sort(a + 1, a + n + 1, greater<int>());
    sort(b + 1, b + m + 1, greater<int>());

    int i = 1, j = 1, k = 1;

    while (k <= n)
    {
        if (j <= m)
        {
            if (a[i] >= b[j])
            {
                s += a[i];
                i++;
            }
            else
            {
                s += b[j];
                j++;
            }
        }
        else
        {
            s += a[i];
            i++;
        }
        k++;
    }

    cout << s;

    return 0;
}
