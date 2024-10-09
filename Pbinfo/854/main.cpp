#include <iostream>
using namespace std;

int main()
{
    int n, k, a[100005], p = 0, poz, nr = 0, i = 1;
    cin >> n >> k;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    for (i = 1; i <= n; ++i)
    {
        if (a[i] % 2)
            ++p;
        if (p == k)
        {
            while(a[i + 1] % 2 == 0 && i < n)
                ++i;
            ++nr, p = 0, poz = i;
        }
    }
    if (p || poz < n)
        ++nr;
    cout << nr;
    return 0;
}
