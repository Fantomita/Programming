#include <iostream>

using namespace std;

//ifstream cin("maxsecvk.in");
//ofstream cout("maxsecvk.out");

int main()
{
    int n, k, q[100005] = {}, x, i = 1, j = 1, maxv = -1000000001;

    cin >> n >> k;
    for (int cnt = 1; cnt <= k; ++cnt)
    {
        cin >> q[i];
        j++;
        maxv = max(maxv, q[i]);
        i++;
    }
    cout << maxv << ' ';
    for (int cnt = k + 1; cnt <= n; ++cnt)
    {
        i++;
        cin >> q[j++];
        maxv = -1000000001;
        for (int jj = i; jj <= j; ++jj)
            maxv = max(maxv, q[jj]);
        cout << maxv << ' ';
    }
}