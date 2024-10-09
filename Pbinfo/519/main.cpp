#include <iostream>
using namespace std;

void citire(int&n, int x[])
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
}

void secv(int n, int x[], int m, int y[])
{
    int p = -1, j;
    for (int i = 1; i <= n; ++i)
    {
        if (x[i] == y[1])
        {
            for (j = i + 1; j < i + m && x[j] == y[j - i + 1] && j <= n; ++j);
            if (j == i + m && p == -1)
            {
                p = i;
                break;
            }
        }
    }
    if (p == -1)
        cout << "NU";
    else
        cout << p;
}

int main()
{
    int n, m, x[1005], y[1005];
    citire(n, x);
    citire(m, y);
    secv(n, x, m, y);
    return 0;
}
