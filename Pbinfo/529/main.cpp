#include <iostream>
using namespace std;

int main()
{
    int n, x, ap[10] = {}, cif[10] = {};
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        while (x)
            ap[x % 10]++, x /= 10;
    }
    for (int i = 0; i <= 9; ++i)
        cif[i] = i;
    for (int i = 0; i < 9; ++i)
        for (int j = i + 1; j <= 9; ++j)
            if (ap[i] > ap[j] || (ap[i] == ap[j] && cif[i] > cif[j]))
                swap(ap[i], ap[j]), swap(cif[i], cif[j]);
    int i = 0;
    while (ap[i] == 0)
        ++i;
    for (; i <= 9; ++i)
        cout << cif[i] << ' ';
    return 0;
}
