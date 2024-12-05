#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005

int n, m;
vector<set<int>> adj(NMAX);
vector<int> degree(NMAX);
queue<int> q;

int main()
{
    ifstream cin("ff.in");
    ofstream cout("ff.out");

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++;
        degree[y]++;
    }

    for (int i = 1; i <= n; ++i)
        if (degree[i] < 2)
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();

        for (auto next : adj[node])
        {
            if (degree[next] > 0)
            {
                degree[next]--;

                if (degree[next] == 1)
                    q.push(next);
            }
        }

        degree[node] = 0;
        q.pop();
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (degree[i] >= 2)
            ans++;

    cout << ans;

    return 0;
}