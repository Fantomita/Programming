#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

bool isPrime(int x)
{
    if (x < 2 || x % 2 == 0 && x != 2) return false;

    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;

    return true;
}

void findPair(int x)
{
    for (int i = 3; i <= x / 2; i += 2)
    {
        if ((x - i) & 1 && isPrime(i) && isPrime(x - i))
        {
            fout << i << ' ' << x - i << '\n';

            return;
        }
    }
}

int main()
{
    int n, v[31], maxEven = -1, minOdd = 10000;

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        if (isPrime(v[i]))
            cout << v[i] << ' ';

        if (v[i] & 1 && v[i] < minOdd)
            minOdd = v[i];
        if (!(v[i] & 1) && v[i] > maxEven)
            maxEven = v[i];
    }
    cout << '\n';

    cout << maxEven << ' ' << minOdd << '\n';

    findPair(maxEven);

    return 0;
}