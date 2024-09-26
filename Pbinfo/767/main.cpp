#include <iostream>
using namespace std;

void citire(int& n, int& m, int a[][101])
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j  = 1; j <= m; ++j)
            cin >> a[i][j];
}

int suma(int n, int m, int a[][101])
{
    int s = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] % 2 == 0)
            s += a[i][j];
    return s;
}

int main()
{
    int a[101][101], n, m;
    citire(n, m, a);
    cout << suma(n, m, a);

    return 0;
}
