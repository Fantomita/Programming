#include <bits/stdc++.h>
using namespace std;

void Impare(int &n)
{
    int cpy = 0, p = 1;

    while(n)
    {
        int uc = n % 10;

        if (uc % 2 == 1)
            cpy = p * (uc - 1) + cpy;
        else
            cpy = p * uc + cpy;

        p *= 10;

        n /= 10;
    }

    n = cpy;
}

int main()
{
    int n = 15690;
    Impare(n);
    cout << n << ' ';

    return 0;
}   