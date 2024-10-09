#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int countDigits(int x)
{
    int cnt = 0;

    do
    {
        cnt++;
        x /= 10;
    } while (x);
    
    return cnt;
}

int main()
{
    int n, v[31], sum = 0;

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];

        if (v[i] & 1)
            sum += v[i];
    }

    for (int i = n; i >= 1; --i)
        cout << v[i] << ' ';
    cout << '\n';

    for (int i = 1; i <= n; ++i)
        cout << countDigits(v[i]) << ' ';
    
    fout << sum;

    return 0;
}