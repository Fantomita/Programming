#include <bits/stdc++.h>

using namespace std;

multiset<tuple<int, int, int>> M;
vector<tuple<int, int, int>> P;
int v[100001];

int main()
{
    ifstream cin("trenuri.in");
    ofstream cout("trenuri.out");

    int n, m, ind = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        M.insert({x, y, i});
    }
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        P.push_back({x, y, i});
    }
    sort(P.begin(), P.end());

    for (int i = m - 1; i >= 0 && !M.empty(); --i)
    {
        int st, cap, pozT;
        int x, y, index;
        tie(x, y, index) = P[i];
        auto it = M.lower_bound({y, 0, 0});
        if (it == M.end())
            continue;
        tie(st, cap, pozT) = *it;
        ind++;
        v[index] = pozT; 
        M.erase(it);
        M.insert({x, 1, pozT});
        if (cap - 1 > 0)
            M.insert({st, cap - 1, pozT});
    }

    cout << ind << '\n';
    for (int i = 1; i <= m; ++i)
        cout << v[i] << '\n';

    return 0;
}