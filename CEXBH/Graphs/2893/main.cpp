#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005
#define inf 0x3f3f3f3f

struct edge
{
    int x, y, cost;
    void swapEdge()
    {
        swap(x, y);
    }
};

int n, m;
vector<edge> v;
vector<int> adj[NMAX], dist(NMAX, inf);
queue<int> q;

int main()
{
    ifstream cin("modernizare.in");
    ofstream cout("modernizare.out");

    dist[1] = 0;

    cin >> n >> m;
    while(m--)
    {
        int j, k, cost;
        cin >> j >> k >> cost;

        edge aux;
        aux = {j, k, cost};
        v.push_back(aux);
        adj[j].push_back(k);
        adj[k].push_back(j);
    }

    q.push(1);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto next : adj[node])
            if (dist[next] == inf)
            {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
    }

    for (int i = 0; i < v.size(); ++i)
    {
        if (dist[v[i].x] > dist[v[i].y])
            v[i].swapEdge();
    }

    sort(v.begin(), v.end(), comp);

    return 0;
}