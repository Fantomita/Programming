#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

bool allEvenDigits(int x)
{
    do
    {
        if (x & 1)
            return false;
        x /= 10;
    } while (x);

    return true;
}

int main()
{
    int n, v[31];
    bool f[10] = {};

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        if (v[i] & 1)
            cout << v[i] << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; ++i)
        if (allEvenDigits(v[i]))
            cout << v[i] << ' ';

    while (v[1])
    {
        f[v[1] % 10] = 1;
        v[1] /= 10;
    }

    for (int i = 9; i > 0; --i)
    {
        if (f[i])
            fout << i;
    }
    fout << ' ';
    for (int i = 1; i < 10; ++i)
    {
        if (f[i])
            fout << i;
    }

    return 0;
}