#include <bits/stdc++.h>
using namespace std;

int n, k, v[101];
int adj[101][101];

int main()
{
    ifstream cin("bipartitcomplet.in");
    ofstream cout("bipartitcomplet.out");

    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        int aux;
        cin >> aux;
        v[aux] = 1;
    }

    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (v[i] != v[j])
                adj[i][j] = adj[j][i] = 1;

    for (int i = 1; i <= n; ++i, cout << '\n')
        for (int j = 1; j <= n; cout << adj[i][j] << ' ', ++j);

    return 0;
}