#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

bool palindrom(int x)
{
    int reversed = 0, cpy = x;
    while (cpy)
    {
        reversed = reversed * 10 + cpy % 10;
        cpy /= 10;
    }

    return reversed == x;
}

int main()
{
    int n, a[21][21], product = 1;

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            fin >> a[i][j];

            cout << a[i][j] << ' ';

            if (j < i)
                product = (product * (a[i][j] % 10)) % 10;
        }
        cout << '\n';
    }

    cout << product;

    bool printed = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (palindrom(a[i][j]))
            {
                fout << a[i][j] << ' ';
                printed = 1;
            }
    if (!printed)
        fout << "Nu exista";

    return 0;
}