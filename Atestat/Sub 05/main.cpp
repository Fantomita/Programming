#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

bool allOddNumbers(int x)
{
    do
    {
        if (!(x & 1))
            return false;
        x /= 10;
    } while (x);

    return true;
}

int primeDivisors(int x)
{
    int d = 2, cnt = 0;

    while (x != 1)
    {
        int p = 0;

        while (x % d == 0)
        {
            x /= d;
            p++;
        }

        if (p)
            cnt++;
        d++;

        if (d * d > x)
            d = x;
    }

    return cnt;
}

int main()
{
    int n, v[31];
    bool printed = 0;

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];

        if (!(v[i] & 1))
            cout << v[i] << ' ';
    }
    cout << '\n';

    for (int i = 1; i <= n; ++i)
    {
        if (allOddNumbers(v[i]))
        {
            cout << v[i] << ' ';
            printed = 1;
        }
    }
    if (!printed)
        cout << "Nu exista";

    int k;
    cout << "\nk = ";
    cin >> k;

    for (int i = 1; i <= n; ++i)
        if (primeDivisors(v[i]) == k)
            fout << v[i] << ' ';
}