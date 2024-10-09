#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define inf 0x3f3f3f3f

using namespace std;

int n, m, max_len;
vector<int> adj[105], vis(105, inf), ans;

void read() {
    ifstream cin("lungimeminima.in");

    cin >> n >> m;

    int x, y;
    for (int i = 1; i <= m; cin >> x >> y, ++i) {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void bfs(int start) {
    queue<int> q;

    q.push(start);
    vis[start] = 0;

    while(!q.empty()) {
        int node = q.front();

        q.pop();

        for (auto next : adj[node])
            if (vis[next] > vis[node] + 1) {
                vis[next] = vis[node] + 1;
                q.push(next);
            }
    }
}

int main() {
    read();
    bfs(1);



    return 0;
}
