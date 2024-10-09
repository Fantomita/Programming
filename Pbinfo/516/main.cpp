#include <iostream>
using namespace std;

void citire(int& n, int x[], int& p, int& u)
{
    p = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i];
        if (x[i] % 2)
        {
            if (p == 0)
                p = i;
            u = i;
        }
    }
}

int suma(int n, int x[], int p, int u)
{
    int s = 0;
    for (int i = p; i <= u; ++i)
        s += x[i];
    return s;
}

int main()
{
    int n, x[1005], p, u;
    citire(n, x, p, u);
    cout << suma(n, x, p, u);
    return 0;
}
