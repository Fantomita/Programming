#include <bits/stdc++.h>
using namespace std;

#define MOD 555557

int result[2][2];
int mat[2][2];

int main() 
{
    ifstream cin("superperfecte.in");
    ofstream cout("superperfecte.out");

    int n;
    cin >> n;
    n -= 2;

    mat[0][0] = 1;
    mat[0][1] = 0;
    mat[1][0] = 1;
    mat[1][1] = 3;
    result[0][0] = result[1][1] = 1;

    while(n)
    {
        if (n & 1)
        {
            result[0][0] = result[0][0] * mat[0][0] + result[1][0] * mat[1][0];
            result[0][1] = result[0][0] * mat[0][1] + result[1][0] * mat[1][1];
            result[1][0] = result[1][0] * mat[0][0] + result[1][1] * mat[0][1];
            result[1][1] = result[1][0] * mat[1][0] + result[1][1] * mat[1][1];
        }
        
        mat[0][0] = mat[0][0] * mat[0][0] + mat[1][0] * mat[1][0];
        mat[0][1] = mat[0][0] * mat[0][1] + mat[1][0] * mat[1][1];
        mat[1][0] = mat[1][0] * mat[0][0] + mat[1][1] * mat[0][1];
        mat[1][1] = mat[1][0] * mat[1][0] + mat[1][1] * mat[1][1];

        n >>= 1;
    }

    // for (int i = 0; i <= 1; i++, cout << '\n')
    //     for (int j = 0; j <= 1; cout << result[i][j] << ' ', j++);

    if (n == 1) 
    {
        cout << 4 << '\n';
        return 0;
    }

    // int a = 0, b = 3, aux;

    // for (int i = 2; i <= n; ++i) 
    // {
    //     aux = a;
    //     a = (a + b) % MOD;
    //     b = aux * 3 % MOD;

    //     // An+1 = (An + (3 * An-1 ))
    // }

    // cout << (a + b) % MOD;

    cout << (result[1][0] * 3 + result[1][1] * 4) % MOD << '\n';

    return 0;
}
