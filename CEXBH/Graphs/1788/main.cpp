#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

vector<pair<int, int>> adj[100005];
int T, n, s, li = 0, ls = inf, cnt;
int dp[100005];

void dfs(int node, int father, int &energy)
{
    dp[node] = -1;

    for (auto it : adj[node])
    {
        if (it.first == father)
            continue;

        dfs(it.first, node, energy);

        if (dp[it.first] - it.second < 0)
        {
            cnt++;
            dp[it.first] = energy;
        }
        if (dp[it.first] - it.second > dp[node])
        {
            dp[node] = dp[it.first] - it.second;
        }
    }

    if (dp[node] == -1)
    {
        cnt++;
        dp[node] = energy;
    }
}

bool check(int value)
{
    cnt = 0;
    dfs(1, 0, value);

    return cnt <= s;
}

int main()
{
    ifstream cin("rege1.in");
    ofstream cout("rege1.out");

    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> n >> s;
        li = 0, ls = inf;
        for (int i = 1; i < n; ++i)
        {
            int x, y, cost;
            cin >> x >> y >> cost;

            adj[x].push_back(make_pair(y, cost));
            adj[y].push_back(make_pair(x, cost));

            if (cost > li)
                li = cost;
        }

        int ans = 0;
        while (li <= ls)
        {
            int mid = li + (ls - li) / 2;

            if (check(mid))
            {
                ans = mid;
                ls = mid - 1;
            }
            else
                li = mid + 1;
        }
        cout << ans << '\n';

        for (int it = 1; it <= n; ++it)
            vector<pair<int, int>> ().swap(adj[it]);
    }

    return 0;
}