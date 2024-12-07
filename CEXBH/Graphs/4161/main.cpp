#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[105];
vector<int> visited[105], sums(105);

void dijkstra(int node, vector<int> &visited)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, node));
    visited[node] = 0;

    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        for(auto next : adj[node])
        {
            int nextnode = next.second;
            int new_cost = visited[node] + next.first;
            if(visited[nextnode] > new_cost)
            {
                visited[nextnode] = new_cost;
                pq.push(make_pair(new_cost, nextnode));
            }
        }
    }
}


int main()
{
    int n, m;

    ifstream cin("picard.in");
    ofstream cout("picard.out");

    cin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(z, y));
        adj[y].push_back(make_pair(z, x));
    }
    for(int i = 1; i <= n; ++i)
    {
        visited[i] = vector<int>(n + 1, 1e9);
        dijkstra(i, visited[i]);
    }
    int sum = 0, maxim = -1e9;
    for(int i = 1; i <= n; ++i)
    {
        sum = 0;
        for(int j = 1; j <= n; ++j)
            if(visited[i][j] != inf)
            sum += visited[i][j];
        sums[i] = sum;
        if(sum > maxim)
            maxim = sum;

        
    }
    for (int i = 1; i <= n; ++i)
        if (sums[i] == maxim)
            cout << i << ' ';
}