#include <iostream>
using namespace std;

int main()
{
    int a[25][25], n;

    cin >> n;

    for (int i = 1; i <= n; ++i && cout << '\n')
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] = (i * j) % 10;

            cout << a[i][j] << ' ';
        }

    return 0;
}
