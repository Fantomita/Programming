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
    int nr = 0, j;
    for (int i = 1; i <= n; ++i)
    {
        if (x[i] == y[1])
        {
            for (j = i + 1; j < i + m && x[j] == y[j - i + 1]; ++j);
            if (j == i + m)
                ++nr;
        }
    }
    cout << nr;
}

int main()
{
    int n, m, x[1005], y[1005];
    citire(n, x);
    citire(m, y);
    secv(n, x, m, y);
    return 0;
}
