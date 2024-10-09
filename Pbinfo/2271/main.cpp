#include <iostream>
#include <algorithm>

using namespace std;

int v[100005];

int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    sort(v + 1, v + n + 1, greater<int>());

    cout << max(v[1] * v[2], v[n] * v[n - 1]);
    return 0;
}
