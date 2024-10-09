#include <iostream>
using namespace std;

void citire(int& n, int& m, int a[][101])
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
}

void permut_st(int n, int m, int a[][101])
{
    for (int i = 1;  i<= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            a[i][j - 1] = a[i][j];
        a[i][m] = a[i][0];
    }
}

void afis(int n, int m, int a[][101])
{
    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= m; cout << a[i][j] << ' ', ++j);
}

int main()
{
    int n, m, a[101][101];
    citire(n, m, a);
    permut_st(n, m, a);
    afis(n, m, a);
    return 0;
}
