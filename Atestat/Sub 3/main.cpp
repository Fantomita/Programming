#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int bcd(int a, int b)
{
    if (b == 0) return a;
    return bcd(b, a % b);
}

int main()
{
    int n, v[31], a = INT_MAX, b = INT_MIN;

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        if (!(v[i] & 1))
            cout << v[i] << ' ' ;

        a = min(a, v[i]);
        b = max(b, v[i]);
    }
    cout << '\n';

    cout << a << '\n' << b << '\n';    

    fout << bcd(a, b) << '\n';

    return 0;
}