#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

bool isPrime(int x)
{
    if (x < 2 || x % 2 == 0 && x != 2)  return false;

    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0) return false;

    return true;
}

int main()
{
    int n, a[21][21];

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

    for (int i = 1; i <= n; ++i)
        a[i][n - i + 1] = k;

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; cout << a[i][j] << ' ', ++j)
        {
            if (isPrime(a[i][j]))
                fout << a[i][j] << ' ';
        }




    return 0;
}