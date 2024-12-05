#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005
#define inf 99999999 

int n, r, b;
int ans = inf;
vector<int> adj[NMAX], adjT[NMAX];
queue<int> qr, qb, qRoot;
int distRoot[NMAX], distRed[NMAX], distBlack[NMAX];

void bfs(queue<int> &q, int dist[], vector<int> a[NMAX])
{
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto &next : a[node])
        {
            if (dist[next] > dist[node] + 1)
            {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
}

signed main()
{
    ifstream cin("rbtree.in");
    ofstream cout("rbtree.out");

    fill (distRoot, distRoot + NMAX, inf);
    fill (distRed, distRed + NMAX, inf);
    fill (distBlack, distBlack + NMAX, inf);

    cin >> n >> r >> b;
    for (int i = 1; i <= r; ++i)
    {
        int x;
        cin >> x;
        qr.push(x);
        distRed[x] = 0;
    }
    for (int i = 1; i <= b; ++i)
    {
        int x;
        cin >> x;
        qb.push(x);
        distBlack[x] = 0;
    }

    for (int i = 1; i <= n; ++i)
    {
        int neighbors;
        cin >> neighbors;
        for (int j = 1; j <= neighbors; ++j)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
            adjT[x].push_back(i);
        }
    }

    distRoot[1] = 0;
    qRoot.push(1);
    bfs(qr, distRed, adjT);
    bfs(qb, distBlack, adjT);
    bfs(qRoot, distRoot, adj);

    // for (int i = 1; i <= n; ++i)
    //     cout << distRoot[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; ++i)
    //     cout << distRed[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; ++i)
    //     cout << distBlack[i] << ' ';
    // cout << '\n';

    for (int i = 1; i <= n; ++i)
        ans = min(ans, distRoot[i] + distRed[i] + distBlack[i]);

    if (ans == inf)
        cout << "impossible";
    else
        cout << ans;



    return 0;
}