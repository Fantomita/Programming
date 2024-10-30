#include <bits/stdc++.h>
using namespace std;

#define MOD 30103
#define int long long int

int fastExp(int base, int exp)
{
    if(exp == 0) return 1;

    int aux = fastExp(base, exp / 2) % MOD;
    
    aux = (aux * aux) % MOD;
    
    if(exp & 1)
        return (aux * base) % MOD;
    else
        return aux;
    
}


//even = {2, 4, 6, 8}
//uneven = {1, 3, 5, 7, 9}
//edcba
// daca N par atunci (fastExp(5, (n - 1) / 2 + 1) * fastExp(4, (n - 1) / 2) + fastExp(4, (n - 1) / 2 + 1) * fastExp(5, (n - 1) / 2) )) * 9

// 5 * 4 * 5 * 4
// 4 * 5 * 4 * 5

// 5 * 4 * 5 * 4 * 5
// 4 * 5 * 4 * 5 * 
signed main()
{
    int n;
    cin >> n;

    if(!(n & 1))
        cout << (2 * 1LL * fastExp(5, n / 2 ) * fastExp(4, n / 2)) % MOD;
    else
        cout << (9 * 1LL * fastExp(5, n / 2 ) * fastExp(4, n / 2)) % MOD;


    return 0;
}