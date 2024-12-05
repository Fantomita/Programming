#include <bits/stdc++.h>
using namespace std;

#define NMAX 105

int n, x;
vector<set<int>> adj(NMAX);
vector<char> visited(NMAX, ' ');

void dfs(int node, char direction)
{
    visited[node] = direction;

    for (auto next :  adj[node])
    {
        if (visited[next] == ' ')
        {
            if (direction == 'S')
                dfs(next, 'D');
            else
                dfs(next, 'S');   
        }
    }
}

int main()
{
    ifstream cin("gears.in");
    ofstream cout("gears.out");

    cin >> n >> x;
    for (int i = 1; i < n; ++i)
    {
        int j, k;
        cin >> j >> k;
        adj[j].insert(k);
        adj[k].insert(j);
    }

    dfs(x, 'D');

    for (int i = 1; i <= n; ++i)
        cout << visited[i];

    return 0;
}