#include <iostream>
using namespace std;

void citire(int& n, int& t, int& k, int v[])
{
    cin >> n >> t >> k;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
}

int secv(int n, int t, int k, int v[])
{
    int i = 1, nr = 0, m = 0;
    while (i <= n)
    {
        if (v[i] <= t)
            m++;
        else m = 0;
        if (m == k)
            m--, nr++;
        ++i;
    }
    return nr;
}

int main()
{
    int v[100005], n, t, k;
    citire(n, t, k, v);
    cout << secv(n, t, k, v);
    return 0;
}
