#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void modifyMatrix(int n, int a[11][11], int k)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i == k || j == k)
                a[i][j] = 1;
}

int main()
{
    int n, a[11][11] = {}, x, y;

    fin >> n;
    while (fin >> x >> y)
        a[x][y] = a[y][x] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }

    for (int i = 1; i <= n; ++i)
    {
        bool isolated = 1;
        for (int j = 1; j <= n && isolated; ++j)
            if (a[i][j])
                isolated = 0;

        if (isolated)
            cout << i << ' ';
    }

    int v;
    cout << "\nv = ";
    cin >> v;

    modifyMatrix(n, a, v);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            fout << a[i][j] << ' '; 

        cout << '\n';
    }

    return 0;
}