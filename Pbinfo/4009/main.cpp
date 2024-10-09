#include <iostream>
#include <algorithm>

using namespace std;

int n, s, v[1005];

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    sort(v + 1, v + n + 1);

    int k = 1;
    while(s >= v[k] && k <= n)
    {
        s -= v[k];
        k++;
    }

    cout << k - 1 << ' ';
    if (k > n)
        cout << 0;
    else
        cout << v[k] - s;

    return 0;
}
