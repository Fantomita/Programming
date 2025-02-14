#include <iostream>
using namespace std;

void Putere(int n, int &x, int &p)
{
    for (int d = 2; d <= n; ++d)
    {
        int k = 0, cpy = n;
        while (cpy % d == 0)
        {
            cpy /= d;
            k++;
        }
        if (cpy == 1)
        {
            x = d;
            p = k;

            return;
        }
    }
}

int main()
{
    int n, x = 0, p = 0;
    cin >> n;
    Putere(n, x, p);
    cout << x << ' ' << p;

    return 0;
}