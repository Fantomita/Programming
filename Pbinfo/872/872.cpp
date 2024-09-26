#include <iostream>
#include <cmath>

using namespace std;

void putere(int n)
{
    int p, x;
    if (n)
    {
        p = 0;
        while (pow(2, p) < n)
            p++;
        if (pow(2, p) > n)
            x = pow(2, p - 1);
        else
            x = pow(2, p);
        putere(n - x);
        cout << x << ' ';
    }
}

int main()
{
    int n;
    cin >> n;
    putere(n);
}