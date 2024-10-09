#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("sumesecv.in", "r", stdin);
    freopen("sumesecv.out", "w", stdout);

    int n, s[105] = {}, k;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    cin >> k;
    for (int i = 1; i <= k; ++i)
    {
        int x, y;
        cin >> x >> y;
        cout << s[y] - s[x - 1] << ' ';
    }

    return 0;
}
