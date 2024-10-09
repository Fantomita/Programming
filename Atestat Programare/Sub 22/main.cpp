#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

struct fraction
{
    int a, b;
}v[11];

bool irreductible(fraction x)
{
    int a = x.a, b = x.b, r;
    while (b)
    {
        r = a % b;

        a = b;
        b = r;
    }

    if (a != 1)
        return false;
    return true;
}

int main()
{
    int n;
    int maxNumerator = -1, itMax;

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i].a >> v[i].b;

        cout << v[i].a << '/' << v[i].b << ' ';

        if (maxNumerator < v[i].a)
        {
            maxNumerator = v[i].a;
            itMax = i;
        }
    }
    cout << '\n';
    cout << v[itMax].a << '/' << v[itMax].b << '\n';

    for (int i = 1; i <= n; ++i)
        if (irreductible(v[i]))
            fout << v[i].a << '/' << v[i].b << ' ';

    return 0;
}