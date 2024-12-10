#include <bits/stdc++.h>
using namespace std;

int TreiCifImp(int n)
{
    int cnt = 0;
    while (n)
    {
        if (n & 1)
            cnt++;
        else
            cnt = 0;

        if (cnt == 3)
            return 1;

        n /= 10;
    }

    return 0;
}

int main()
{
    

    return 0;
}   