#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005

int n, m, x;
vector<int> adj[NMAX], source(NMAX), dist(NMAX);
queue<int> q;

int main()
{
    ifstream cin("reinvent.in");
    ofstream cout("reinvent.out");

    cin >> n >> m >> x;
    while(m--)
    {
        int j, k;
        cin >> j >> k;

        adj[j].push_back(k);
        adj[k].push_back(j);
    }
    while(x--)
    {
        int i;
        cin >> i;

        source[i] = i;
        q.push(i);
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto next : adj[node])
        {
            if (!source[next])
            {
                source[next] = source[node];
                dist[next] = dist[node] + 1;
                q.push(next);
            }
            else if (source[next] != source[node])
            {
                cout << dist[node] + dist[next] + 1;
                return 0;
            }
        }
    }
    return 0;
}