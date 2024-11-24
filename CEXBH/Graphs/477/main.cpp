#include <bits/stdc++.h>
using namespace std;

int n, m, p, q, r;
set<int> adj[25];
vector<bool> visited(25, 0);
vector<int> path;

void dfs(int node, ofstream &cout)
{
    visited[node] = 1;
    path.push_back(node);

    if (node == q)
    {
        for (auto it : path)
            cout << it << ' ';
        cout << '\n';
    }

    for (auto next : adj[node])
        if (!visited[next] && next != r)
            dfs(next, cout);

    visited[node] = 0;
    path.pop_back();
}

int main()
{
    ifstream cin("lanturi1.in");
    ofstream cout("lanturi1.out");

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    cin >> p >> q >> r;

    dfs(p, cout);

    return 0;
}