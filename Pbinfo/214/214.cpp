#include <iostream>
using namespace std;

int main()
{
    int a[10], n, m = 0;

    cin >> n; 
    do
    {
        a[++m] = n % 10;
        n /= 10;
    } while (n);

    for (int i = 1; i <= m; ++i && cout << '\n')
        for (int j = 1; j <= m; ++j)
            cout << a[j] << ' ';

    return 0;
}
