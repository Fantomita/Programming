#include <bits/stdc++.h>
using namespace std;

#define MOD 777013

int main()
{
    
    int N;
    cin >> N;
    long long s1 = 26, s2 = 0;

    for (int i = 2; i <= N; ++i) 
    {
        long long new_s1 = ((s1 + s2) * 25) % MOD;

        long long new_s2 = s1 % MOD;

        s1 = new_s1;
        s2 = new_s2;
    }

    cout << (s1 + s2) % MOD << '\n';

    return 0;
}