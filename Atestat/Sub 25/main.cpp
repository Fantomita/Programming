#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void modifyMatrix(int n, int a[11][11])
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                a[i][j] = 1;
}

int main()
{
    int n, a[11][11] = {};

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        fin >> x >> y;

        a[x][y] = a[y][x] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }

    int v, rank = 0;
    cout << "v = ";
    cin >> v;
    
    for (int i = 1; i <= n; ++i)
        rank += a[i][v];
    cout << rank;

    modifyMatrix(n, a);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << a[i][j] << ' ';
        fout << '\n';
    }

    return 0;
}