#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <climits>
using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

bool isPrime(int x)
{
    if (x < 2 || (x != 2 && x % 2 == 0)) return false;
    for (int d = 2; d * d <= x; ++d)
        if (x % d == 0)
            return false;
    return true;
}

int main()
{
    int n, v[20], maxP = -1, minI = INT_MAX;
    
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        if (isPrime(v[i]))
            cout << v[i] << ' ';
    }
    cout << '\n';


    return 0;
}