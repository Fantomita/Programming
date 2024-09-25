#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a[7][7] = {}, n;

    cin >> n;

    for (int i = 1; i <= 5; ++i, n /= 10)
        for (int j = i + 1; j <= 6; ++j)
        {
            if (i != j)
                a[i][j] = a[j][i] = n % 10;
        }

    for (int i = 1; i <= 6; ++i, cout << '\n')
        for (int j = 1; j <= 6; cout << a[i][j] << ' ', ++j);

    return 0;
}
