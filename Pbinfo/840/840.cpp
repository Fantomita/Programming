#include <fstream>
using namespace std;

ifstream cin("croco.in");
ofstream cout("croco.out");

const int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };

int a[105][105], n, m;

void afill(int i, int j, int c)
{
    a[i][j] = c;
    int ii, jj;
    for (int k = 0; k < 4; ++k)
    {
        ii = i + di[k];
        jj = j + dj[k];
        if (ii > 0 && ii <= n && jj > 0 && jj <= m && a[ii][jj] == 1)
            if (c == 2)
                afill(ii, jj, 3);
            else
                afill(ii, jj, 2);
    }
        
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == 1)
                afill(i, j, 2);                

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == 0)
                cout << "A ";
            else if (a[i][j] == 2)   
                cout << "C ";
            else if (a[i][j] == 3)
                cout << "E ";
        }
}
