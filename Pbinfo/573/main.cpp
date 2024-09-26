#include <iostream>

using namespace std;

int main()
{
    int n, m, adj[105][105] = {}, cnt = 0, q[105], maxSInt = -1;

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;

        adj[a][b] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        int sInt = 0, sExt = 0;
        for (int j = 1; j <= n; ++j)
            sInt += adj[j][i], sExt += adj[i][j];

        if (maxSInt < sInt)
        {
            cnt = 0;
            q[++cnt] = i;
            maxSInt = sInt;
        }
        else if (maxSInt == sInt)
            q[++cnt] = i;
    }

    for (int i = 1; i <= cnt; ++i)
        cout << q[i] << ' ';

    return 0;
}
