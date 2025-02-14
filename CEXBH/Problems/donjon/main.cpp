#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
h + h + 1 + h + 2 + ... + h + k - 1 == k * h + (k * (k - 1)) / 2
*/

int XOR(int x)
{
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
}

signed main()
{
    ifstream cin("donjon.in");
    ofstream cout("donjon.out");

    int Q;
    cin >> Q;
    while(Q--)
    {
        int n, k;
        cin >> n >> k;

        int sum = (k * (k - 1)) / 2, h = (n - sum) / k;
        //cout << sum << ' ';
        if (n - sum < 0 || (n - sum) % k != 0)
        {
            cout << "C\n";
            continue;
        }
        
        if (XOR(h - 1) ^ XOR(h + k - 1))
            cout << "G " << h << '\n';
        else
            cout << "C " << h << '\n';
    }

    return 0;
}