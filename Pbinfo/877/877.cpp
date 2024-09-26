#include <iostream>
#include <cstring>
using namespace std;

struct el
{
    int v, p;
}s[1001];

int main()
{
    int n, k = -1, x;

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        while(k >= 0 && s[k].v < x)
            k--;
        s[++k].v = x;
        s[k].p = i;
    }

    cout << k + 1 << '\n';
    for (int i = 0; i <= k; ++i)
        cout << s[i].p << ' ';

    return 0;
}
