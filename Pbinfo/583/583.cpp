#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x, y, cnt;
vector<int> adj[105], adj_transp[105], s, ctc[105];
vector<bool> viz;
vector<pair<int, int>> useless;

void read()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj_transp[y].push_back(x);
    }
}

void dfs(int k)
{
    viz[k] = true;
    for (auto x : adj[k])
        if(!viz[x])
            dfs(x);
    s.push_back(k);
}

void dfs_transp(int k)
{
    viz[k] = true;
    ctc[cnt].push_back(k);
    for (auto x : adj_transp[k])
        if(!viz[x])
            dfs_transp(x);
}

int main()
{
    read();

    viz = vector<bool> (n + 1, false);
    for (int i = 1; i <= n; ++i)
        if (!viz[i])
            dfs(i);

    int cnt = 0;

    viz = vector<bool> (n + 1, false);
    reverse(s.begin(), s.end());
    for (auto &x : s)
        if(!viz[x])
        {
            cnt++;
            dfs_transp(x);
        }

    for (int i = 1; i <= n; ++i)
        for (auto next : adj[i])
            if(viz[i] != viz[next])
                useless.push_back({i, next});

    sort(useless.begin(), useless.end());
    cout << useless.size() << '\n';

    for (auto el : useless)
        cout << el.first << ' ' << el.second << '\n';

    cout << cnt;

}