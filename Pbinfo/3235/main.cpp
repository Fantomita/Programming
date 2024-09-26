#include <bits/stdc++.h>

#define NMAX 5005
#define PMAX 20001

using namespace std;

int T[PMAX], rang[PMAX], n;
unordered_map <int, int> index_comp;

int root(int k)
{
    if (T[k] == 0)
        return k;
    else
    {
        int x = root(T[k]);
        T[k] = x;
        return x;
    }
}

void unite(int k, int p)
{
    int rk = root(k), rp = root(p);

    if (rk != rp)
    {
        if (rang[rk] > rang[rp])
            T[rp] = rk;
        else
        {
            T[rk] = rp;
            if (rang[rk] == rang[rp])
                rang[rp]++;
        }
    }
}

void read()
{
    ifstream cin("entries.in");
    ofstream cout("entries.out");

    int x, y, q;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y >> q;

        if (index_comp[x] == 0) index_comp[x] = index_comp.size();
        if (index_comp[y] == 0) index_comp[y] = index_comp.size();

        x = index_comp[x];
        y = index_comp[y];

        x = root(x);
        y = root(y);

        if (q == 1)
        {
            if (x != y)
                unite(x, y);
        }
        else
            cout << (x == y) << '\n';

    }
}

int main()
{
    read();
    return 0;
}
