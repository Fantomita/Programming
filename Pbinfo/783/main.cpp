#include <iostream>

using namespace std;

int main()
{
    int n, a[105][105], sum = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];

            if (j == i + 1)
                sum += a[i][j];
            if (j == i - 1)
                sum += a[i][j];
        }
    }

    cout << sum;

    return 0;
}
