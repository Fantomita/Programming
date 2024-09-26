#include <iostream>
using namespace std;

int main()
{
    int f[105] = {}, n, x, s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        f[x]++;
    }
    for (int i = 1; i <= n; ++i)
        s += f[i] / 2;
    cout << s;
    return 0;
}
