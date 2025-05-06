#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool isInside(const vector<vector<int>>& mat, int i, int j)
{
    return (i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size());
}

int dfs(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visited) 
{
    if (!isInside(map, x, y) || visited[x][y]) 
    {
        return 0;
    }
    
    visited[x][y] = true;

    if (map[x][y] == 9)
    {
        return 1;
    }

    int score = 0;

    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (isInside(map, nx, ny) && map[nx][ny] == map[x][y] + 1) 
            score += dfs(nx, ny, map, visited);
    }

    return score;
}

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    vector<vector<int>> mat;
    queue<pair<int, int>> q;
    string line;

    while (getline(cin, line))
    {
        vector<int> row;
        for (const auto& it : line)
        {
            row.push_back(it - '0');
            if (it - '0' == 0)
                q.push({mat.size(), row.size() - 1});
        }
        mat.push_back(row);
    }

    int ans = 0;

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        int score = dfs(i, j, mat, visited);
        ans += score;
    }

    cout << ans;

    return 0;
}
