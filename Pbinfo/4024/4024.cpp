/*
A_initial
1 2 3
4 5 0
9 3 7

S_initial
0 0 0
0 0 0
0 0 0

A_final
0 2 11
4 29 29
49 91 210

S_final
1 3 6
5 10 10 
14 17 24 
*/

#include <fstream>
using namespace std;

ifstream cin("matprod.in");
ofstream cout("matprod.out");

int a[1005][1005], s[1005][1005], n;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= n; ++i)
    {
        s[i][1] = s[i - 1][1] + a[i][1];
        a[i][1] = a[i - 1][1] + a[i][1] * s[i - 1][1];
    }
        

    for (int j = 2; j <= n; ++j)
        for (int i = 1; i <= n; ++i)
        {
            s[i][j] = s[i][j - 1] + a[i][j];
            a[i][j] = a[i][j - 1] + a[i][j] * s[i][j - 1];
        }
    
    /*
    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; ++j)
            cout << s[i][j] << ' ';
    */
    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';

    return 0;
}