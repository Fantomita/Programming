#include <iostream>
using namespace std;

void citire(int& n, int& m, int a[][101])
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j  = 1; j <= m; ++j)
            cin >> a[i][j];
}

void suma(int n, int m, int a[][101])
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            a[i][0] += a[i][j];
        cout << a[i][0] << ' ';
    }
}

int main()
{
    int a[101][101] = {}, n, m;
    citire(n, m, a);
    suma(n, m, a);

    return 0;
}
