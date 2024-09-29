#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void printWays(int n, int a[11][11], int v)
{
    for (int i = 1; i <= n; ++i)
        if (a[v][i])
            for (int j = 1; j <= n; ++j)
                if (a[i][j])
                    fout << v << ' ' << i << ' ' << j << '\n';
}

int main()
{
    int n, a[11][11] = {}, x, y;

    fin >> n;
    while (fin >> x >> y)
        a[x][y] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }

    int v, rankExt = 0, rankInt = 0;
    cout << "v = ";
    cin >> v;

    for (int i = 1; i <= n; ++i)
    {
        rankExt += a[i][v];
        rankInt += a[v][i];
    }
    cout << rankExt << ' ' << rankInt << '\n';

    printWays(n, a, v);
    
    return 0;
}