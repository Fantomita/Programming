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
    while (fin >> x >> y)
        a[x][y] = 1;
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

void equalRanks()
{
    for (int node = 1; node <= n; ++node)
    {
        int rankExt = 0, rankInt = 0;

        for (int i = 1; i <= n; ++i)
            rankExt += a[node][i];

        for (int i = 1; i <= n; ++i)
            rankInt += a[i][node];

        if (rankExt == rankInt)
            cout << node << ' ';
    }
}

void isPath()
{
    bool ok = 1;
    int x, last;
    cout << "\nEnter nodes: ";
    cin >> last;
    while (cin >> x && ok)
    {
        if (!x)
            break;

        if (!a[last][x])
            ok = 0;
        last = x;
    }

    cout << (ok ? "DA" : "NU");
}



int main()
{
    read();
    print();
    equalRanks();
    isPath();
    return 0;
}