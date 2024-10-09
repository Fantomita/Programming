#include <iostream>

using namespace std;

int main()
{
    int n, m, a[22][22], ok = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            if (j > m / 2)
                if (a[i][m - j + 1] != a[i][j])
                    ok = 0;
        }

    cout << (ok == 1 ? "DA" : "NU");
}
