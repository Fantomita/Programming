#include <bits/stdc++.h>
using namespace std;

#define NMAX 1005

int n, m, q;
vector<set<int>> adj(NMAX);
vector<int> visited(NMAX), conexComponents = {0, };

int dfs(int node, int cnt) 
{
    visited[node] = cnt;
    int size = 1;

    for (auto next : adj[node]) 
    {
        if (!visited[next]) 
        {
            size += dfs(next, cnt);
        }
    }

    return size;
}


int main()
{
    ifstream cin("componenteconexe5.in");
    ofstream cout("componenteconexe5.out");

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    int it = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            conexComponents.push_back(dfs(i, it++));
        }
    }

    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        int x;
        cin >> x;

        cout << conexComponents[visited[x]] << '\n';
    }

    return 0;
}