#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> adj[25];
vector<int> path;
bool visited[25];
bool ok = 0;

void dfs(int node, ofstream &fout)
{
    visited[node] = true;
    path.push_back(node);

    if (path.size() == n)
    {
        ok = 1;
        for (auto it : path)
            fout << it << ' ';
        fout << '\n';
    }

    for (auto next : adj[node])
    {
        if (!visited[next])
            dfs(next, fout);
    }

    path.pop_back();
    visited[node] = false;
}

int main()
{
    ifstream cin("capradinohio.in");
    ofstream cout("capradinohio.out");

    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    for (int i = 1; i <= n; ++i)
    {
        fill(visited, visited + n + 1, false);
        dfs(i, cout);
    }

    if (!ok)
    {
        cout << "NU EXISTA\n";
        return 0;
    }

    return 0;
}