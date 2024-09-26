#include <iostream>
using namespace std;

void sortare(int n, int m, int a[105][105])
{
    for (int i = 1; i < n; ++i)
    {
        for (int k = i + 1; k <= n; ++k)
        {
            if (a[i][0] > a[k][0])
                for (int j = 0; j <= m; ++j)
                    swap(a[i][j], a[k][j]);
        }
    }     
}

int main()
{
    int a[105][105] = {}, n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            a[i][0] += a[i][j];
        }
    }

    sortare(n, m, a);

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= m; cout << a[i][j] << ' ', ++j);

    return 0;
}
