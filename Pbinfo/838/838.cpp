#include <iostream>
#include <fstream>
using namespace std;

ifstream in("iesire.in");
ofstream out("iesire.out");

const int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };

int a[105][105], n, m, x, y;

void afill(int i, int j)
{
    a[i][j] = 2;
    for (int k = 0; k < 4; ++k)
    {
        int ii, jj;
        ii = i + di[k];
        jj = j + dj[k];
        if (ii > 0 && ii <= n && jj > 0 && jj <= n && a[ii][jj] == 0)
            afill(ii, jj);
    }
}

int main()
{
    in >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            in >> a[i][j];
    for (int i = 1; i <= n; ++i)
    {
        if (a[i][1] == 0)
            afill(i, 1);
        if (a[i][n] == 0)
            afill(i, n);
        if (a[1][i] == 0)
            afill(1, i);
        if (a[n][i] == 0)
            afill(n, i);
    }

    /*
    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << " ";
    */

    for (int i = 1; i <= m; ++i)
    {
        in >> x >> y;
        if (a[x][y] == 2)
            out << "da\n";
        else
            out << "nu\n";
    }

    return 0;
}