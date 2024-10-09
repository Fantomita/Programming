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

void isPath()
{
    bool ok = 1;
    int x, last;
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

void printAdjacentList()
{
    int v;
    cout << "\nv = ";
    cin >> v;

    for (int i = 1; i <= n; ++i)
        if (a[i][v])
            fout << i << ' ';
}

int main()
{
    read();
    print();
    isPath();
    printAdjacentList();

    return 0;
}