#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

bool isPalindrom(int x)
{
    int cpy = x, reversed = 0;

    do
    {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    } while (x);

    return cpy == reversed;
}

int numberOfDivs(int x)
{
    int nr = 0;
    for (int d = 2; d * d <= x; ++d)
    {
        if (x % d == 0)
        {
            nr++;
            if (d != x / d)
                nr++;
        }
    }

    return nr;
}

int main()
{
    int n, v[16];

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];

        if (isPalindrom(v[i]))
            cout << v[i] << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; ++i)
    {
        cout << numberOfDivs(v[i]) << ' ';
        if (v[i] & 1)
            fout << v[i] << ' ';
    }

    return 0;
}