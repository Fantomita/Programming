#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 666013

struct mat
{
    int a11, a12, a21, a22;
};

mat matMul(mat mat1, mat mat2)
{
    mat res;
    res.a11 = ((1LL * mat1.a11 * mat2.a11) % MOD + (1LL * mat1.a12 * mat2.a21) % MOD) % MOD;
    res.a12 = ((1LL * mat1.a11 * mat2.a12) % MOD + (1LL * mat1.a12 * mat2.a22) % MOD) % MOD;
    res.a21 = ((1LL * mat1.a21 * mat2.a11) % MOD + (1LL * mat1.a22 * mat2.a21) % MOD) % MOD;
    res.a22 = ((1LL * mat1.a21 * mat2.a12) % MOD + (1LL * mat1.a22 * mat2.a22) % MOD) % MOD;
    return res;
}

mat matPow(mat mat1, int n)
{
    mat ans = {1, 0, 0, 1};
    while (n)
    {
        if (n % 2)
            ans = matMul(ans, mat1);
        mat1 = matMul(mat1, mat1);
        n /= 2;
    }
    return ans;
}

signed main()
{
    ifstream cin("kfib.in");
    ofstream cout("kfib.out");

    int n;
    cin >> n;

    mat ans = matPow({1, 1, 1, 0},  n - 1);

    cout << ans.a11 << endl;

    return 0;
}