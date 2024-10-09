#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

bool findInMatrix(int n, int a[11][11], int k)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j] == k)
                return true;

    return false;
}

int main()
{
    int n, a[11][11];

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            fin >> a[i][j];

            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    int k;
    cout << "k = ";
    cin >> k;

    cout << (findInMatrix(n, a, k) ? "DA" : "NU");

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == n)
                a[i][j] = 0;
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }

    return 0;
}