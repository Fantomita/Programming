#include <iostream>

using namespace std;

int cmmdc(int a, int b)
{
    if (b == 0) return a;
    return cmmdc(b, a % b);
}

int main()
{
    int n, sumUp = 0, sumDn = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int x;
            cin >> x;

            if (i < j)
                sumUp += x;
            else if (i != j)
                sumDn += x;
        }
    }

    cout << cmmdc(sumUp, sumDn);

    return 0;
}