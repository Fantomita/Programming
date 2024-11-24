#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 25;

int n, m, l;
bool found;
set<int> adj[MAX_NODES];
vector<int> path;
vector<bool> visited(MAX_NODES);

void dfs(int node, ofstream &cout)
{
    if (found)
        return;

    visited[node] = true;
    path.push_back(node);

    if (path.size() == l)
    {
        if (adj[node].count(path[0]))
        {
            for (int node : path)
                cout << node << ' ';

            cout << path[0];

            found = true;
        }
    }
    else
    {
        for (int next : adj[node])
            if (!visited[next])
                dfs(next, cout);
    }

    visited[node] = false;
    path.pop_back();
}

int main()
{
    ifstream cin("ciclul.in");
    ofstream cout("ciclul.out");

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;

        adj[x].insert(y);
        adj[y].insert(x);
    }
    cin >> l;

    for (int i = 1; i <= n && !found; ++i)
        dfs(i, cout);

    return 0;
}