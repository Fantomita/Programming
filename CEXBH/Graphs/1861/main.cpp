    #include <bits/stdc++.h>
    using namespace std;

    vector<int> adjT[100005];
    int visited[100005];
    vector<int> sortedGraph;

    void dfs(int node)
    {
        visited[node] = 1;

        for (auto next : adjT[node])
        {
            if (!visited[next])
            {
                dfs(next);
            }
        }

        sortedGraph.push_back(node);
    }

    int main()
    {
        ifstream cin("topsort.in");
        ofstream cout("topsort.out");

        int n, m;

        cin >> n >> m;

        for (int i = 1; i <= m; ++i)
        {
            int a, b;
            cin >> a >> b;
            adjT[b].push_back(a);
        }

        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }

        //reverse(sortedGraph.begin(), sortedGraph.end());

        for (auto node : sortedGraph)
        {
            cout << node << " ";
        }

        return 0;
    }