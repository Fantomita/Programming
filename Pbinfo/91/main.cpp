#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream cin("masini.in");
    ofstream cout("masini.out");

    int n, t, v[1005], k = 0;

    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    sort(v + 1, v + n + 1);

    while(t >= v[++k] && k <= n)
    {
        t -= v[k];
    }
    k--;

    cout << k;
    return 0;
}
