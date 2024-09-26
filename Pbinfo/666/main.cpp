#include <iostream>
using namespace std;

bool prim(int x)
{
    if (x < 2 || x % 2 == 0 && x != 2)
        return 0;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return 0;
    return 1;
}

void citire(int& n, int& m, int a[][101])
{
    int nr = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            if (i % 2 == 0 && prim(a[i][j]))
                ++nr;
        }
    cout << nr;
}

int main()
{
    int n, m, a[101][101];
    citire(n, m, a);
    return 0;
}
