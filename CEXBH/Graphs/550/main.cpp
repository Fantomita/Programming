#include <bits/stdc++.h>
using namespace std;

#define NMAX 1005

int n;
vector<set<int>> adj(NMAX);
vector<int> apples(NMAX);
vector<bool> visited(NMAX);

int dfs(int node)
{
    visited[node] = 1;

    int maxVal = -1, maxIndex = -1;
    for (auto next : adj[node])
    {
        if (!visited[next] && apples[next] > maxVal)
        {
            maxVal = apples[next];
            maxIndex = next;
        }
    }

    if (maxIndex != -1)
        return apples[node] + dfs(maxIndex);
    return apples[node];
}

int main()
{
    ifstream cin("mere.in");
    ofstream cout("mere.out");

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> apples[i];
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }

    cout << dfs(1);

    return 0;
}