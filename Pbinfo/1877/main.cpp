#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, v[1005], s = 0, k;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        s += v[i];
    }
    cin >> k;

    sort(v + 1, v + n + 1);

    while(k >= 1)
    {
        s -= v[k];
        v[k] = -v[k];
        s += v[k];
        k--;
    }

    cout << s;
    return 0;
}
