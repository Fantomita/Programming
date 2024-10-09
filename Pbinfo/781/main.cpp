#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[105][105], n, i, j, s[4] = {};

    cin >> n;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            cin >> a[i][j];

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
        {
            if (j > i && j < n - i + 1)
                s[0] += a[i][j],
                s[3] += a[j][i];
            if (j > n - i + 1 && j > i)
                s[1] += a[i][j],
                s[2] += a[j][i];
        }

    sort(s, s + 3);

    for (i = 0; i < 4; ++i)
        cout << s[i] << ' ';

    return 0;
}
