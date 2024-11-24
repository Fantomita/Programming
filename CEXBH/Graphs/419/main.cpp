#include <bits/stdc++.h>
using namespace std;

set<int> adj[105];
vector<int> degree(105, 0);
int cnt;

int main()
{
    ifstream cin("subgraf1.in");
    ofstream cout("subgraf1.out");

    int n, x, y;
    cin >> n;
    while (cin >> x >> y)
    {
        if (find(adj[x].begin(), adj[x].end(), y) == adj[x].end())
        {
            //cout << x << ' ' << y << '\n';
            cnt++;
            degree[x]++;
            degree[y]++;
            adj[x].insert(y);
            adj[y].insert(x);
        }
    }

    int minv = INT_MAX, nrmin;
    for (int i = 1; i <= n; ++i)
    {
        if (degree[i] < minv)
        {
            minv = degree[i];
            nrmin = 1;
        }
        else if (degree[i] == minv)
            nrmin++;
    }

    cout << cnt - nrmin * minv;

    return 0;
}