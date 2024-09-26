#include <iostream>
using namespace std;

int main()
{
    int a[105][105], n, m, nr;
    cin >> n >> m;
    nr = m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int j = 1; j <= m; ++j)
    {
        int ok = 1;
        for (int i = 1; i < n && ok; ++i)
            for (int k = i + 1; k <= n && ok; ++k)
                if (a[i][j] == a[k][j])
                    ok = 0, nr--;
    }
    cout << nr;
}
