#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int n, a[11][11];

void read()
{
    int x, y;
    fin >> n;
    while(fin >> x >> y)
        a[x][y] = a[y][x] = 1;
}

void print()
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}

void rankMax()
{
    int maxRank = 0;

    for (int i = 1; i <= n; ++i)
    {
        int currentRank = 0;

        for (int j = 1; j <= n; ++j)
            currentRank += a[i][j];
        maxRank = max(maxRank, currentRank);
    }

    for (int i = 1; i <= n; ++i)
    {
        int currentRank = 0;

        for (int j = 1; j <= n; ++j)
            currentRank += a[i][j];

        if (currentRank == maxRank)
            cout << i << ' ';
    }
}

void isolateNode()
{
    int v;
    cout << "\nv = ";
    cin >> v;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == v || j == v)
                a[i][j] = 0;
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }
}

int main()
{
    read();
    print();
    rankMax();
    isolateNode();

    return 0;
}