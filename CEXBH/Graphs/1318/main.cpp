#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> adj[105];
vector<int> colored(105);
bool isBipartite = true;

void dfs(int node, int color)
{
    colored[node] = color;

    for (auto next : adj[node])
    {
        if (!colored[next])
            dfs(next, 3 - color);
        else if (colored[next] == color)
            isBipartite = false;
    }
}

int main()
{
    ifstream cin("bipartit1mare.in");
    ofstream cout("bipartit1mare.out");

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    for (int i = 1; i <= n; ++i)
        if (!colored[i])
            dfs(i, 1);

    if (!isBipartite)
    {
        cout << "NU\n";
        return 0;
    }
    else
    {
        cout << "DA\n";
        for (int i = 1; i <= n; ++i)
            if (colored[i] == 1)
                cout << i << ' ';
        cout << '\n';
        for (int i = 1; i <= n; ++i)
            if (colored[i] == 2)
                cout << i << ' ';
    }

    return 0;
}