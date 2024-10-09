#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int minOnLine(int n, int a[][21], int i)
{
    int minv = 10000;
    for (int j = 1; j <= n; ++j)
        minv = min(minv, a[i][j]);

    return minv;
}

int main()
{
    int n, a[21][21], sum = 0;

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            fin >> a[i][j];

            if (i == j)
                sum += a[i][j];

            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << sum;

    for (int i = 1; i <= n; ++i)
        fout << minOnLine(n, a, i) << ' ';

    return 0;
}