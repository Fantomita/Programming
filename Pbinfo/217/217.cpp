#include <iostream>
using namespace std;

int main()
{
    int a[25][25] = {}, n;

    cin >> n;

    for (int i = 1; i <= n; ++i && cout << '\n')
        for (int j = 1; j <= n; ++j)
        {
            if (i % 2)
                a[i][j] = i;
            else
                a[i][j] = j;
            cout << a[i][j] << ' ';
        }

    return 0;
}
