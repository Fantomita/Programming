#include <iostream>

using namespace std;

int main()
{
    int n, x, sP = 0, sS = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> x;

            if (i == j)
                sP += x;
            if (i + j == n + 1)
                sS += x;
        }
    }

    cout << abs(sP - sS);

    return 0;
}