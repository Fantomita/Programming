#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream cin("graf_partial_2.in");
    ofstream cout("graf_partial_2.out");

    int a[101][101] = {}, n, x, y, maxv = -1, nr = 0;
    cin >> n;
    while (cin >> x >> y)
    {
        if (!a[x][y])
        {
            a[x][0]++;
            a[y][0]++;
            maxv = max(maxv, max(a[x][0], a[y][0]));
        }
        a[x][y] = a[y][x] = 1;
    }

    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if(a[i][0] == maxv || a[j][0] == maxv)
            {
                if (a[i][j])
                    nr++;
                a[i][j] = a[j][i] = 0;
            }

    cout << nr << '\n';
    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';

    return 0;
}
