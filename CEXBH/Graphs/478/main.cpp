#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 25;

int n, m, p;
bool found;
set<int> adj[MAX_NODES];
vector<int> sol;
vector<bool> visited(MAX_NODES);

void backtrack(int k, ofstream &cout)
{
    if (found)
        return;

    if (k > 2)
    {
        if (adj[sol[k-1]].count(p))
        {
            found = true;

            for (int node : sol)
                cout << node << ' ';
            cout << p;

            return;
        }
    }

    for (int next = 1; next <= n; ++next)
    {
        if (visited[next] || !adj[sol[k-1]].count(next))
            continue;

        visited[next] = true;
        sol.push_back(next);

        backtrack(k + 1, cout);

        visited[next] = false;
        sol.pop_back();
    }
}

int main()
{
    ifstream cin("ciclu.in");
    ofstream cout("ciclu.out");

    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;

        adj[x].insert(y);
        adj[y].insert(x);
    }
    cin >> p;

    visited[p] = true;
    sol.push_back(p);

    backtrack(1, cout);

    return 0;
}