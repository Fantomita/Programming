#include <bits/stdc++.h>
using namespace std;

vector<int> adj[105], adjT[105], cost(105), sortedGraph;
int visited[105], late[105];

void dfs(int node)
{
    visited[node] = 1;
    for (auto next : adjT[node])
        if (!visited[next])
            dfs(next);
    sortedGraph.push_back(node);
}

int main()
{
    ifstream cin("pm.in");
    ofstream cout("pim.out");

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> cost[i];

    for (int i = 1; i <= n; ++i)
    {
        int m;
        cin >> m;

        if (m == 0)
        {
            adj[0].push_back(i);
            adjT[i].push_back(0);
        }
        
        for (int j = 1; j <= m; ++j)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
            adjT[x].push_back(i);
            late[x]++;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (late[i] == 0)
        {
            adj[i].push_back(n + 1);
            adjT[n + 1].push_back(i);
        }
    }

    dfs(0);

    return 0;
} 