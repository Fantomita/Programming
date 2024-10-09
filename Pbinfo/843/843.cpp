#include <iostream>
#include <cmath>

using namespace std;

unsigned long long putere(int a, int n, int p)
{
    if (n)
        if (n % 2 == 0)
            return (unsigned long long)pow(putere(a, n / 2, p), 2) % p;
        else
            return (putere(a, n - 1, p) * a) % p;
    else return 1;
}

int main()
{
    int n, a, p, pt = 10;
    cin >> a >> n >> p;
    while(p > 1)
    {
        pt *= 10;
        p--;
    }
    cout << putere(a, n, pt);
}