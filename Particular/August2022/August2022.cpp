#include <iostream>
using namespace std;

void schimb(int& n, int x, int p)
{
    int powr = 1;
    while (p--)
        powr *= 10;
    n = (n / (powr * 10) * 10 + x) * powr + n % powr;
}

int main()
{
    int n, x, p;
    cin >> n >> x >> p;

    schimb(n, x, p);
    cout << n;

    return 0;
}