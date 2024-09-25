#include <iostream>
using namespace std;

int main()
{
    int a[16][16] = {}, n, i, j;

    cin >> n;

    for (j = n; j >= 1; j--)
    {
        for (i = 1; i <= n; i++)
        {
            if (i == 1 || j == 1 || i == n || j == n)
                a[i][j] = i + j;
            else
                a[i][j] = a[i - 1][j + 1] + a[i][j + 1] + a[i + 1][j + 1];
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << '\n';
    }

    return 0;
}