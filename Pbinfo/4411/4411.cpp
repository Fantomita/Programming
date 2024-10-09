#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#define inf 0x3f3f3f3f
#define NMAX 5005
#define pii pair<int, int>

using namespace std;

vector<int> adj[NMAX];
int n, m, x, y, question, s, a, b;

void read()
{
    cin >> question >> n >> m >> s >> a >> b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        adj[y].push_back(x);
    }
}

int viz[NMAX], d1[NMAX], d2[NMAX];

void dfs(int node, int d[])
{
    viz[node] = 1;

    for (auto next : adj[node])
    {
        if (viz[next]) continue;
        d[next] = node;
        dfs(next, d);
    }
}

void solve1()
{
    dfs(a, d1);
    fill(viz, viz + NMAX, 0);
    dfs(b, d2);
    
    for (int i = 1; i <= n; ++i)
        cout << d1[i] << ' ';
    cout << '\n';
    
    for (int i = 1; i <= n; ++i)
        cout << d2[i] << ' ';
    cout << '\n';
    
    for (int i = n; i >= 1; --i)
    {
        if (d1[i] && d2[i])
            cout << i << ' ';
    }
}

int main()
{
    read();
    solve1();

    return 0;
}