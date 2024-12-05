#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream cin ("input.in");
    ofstream cout ("output.out");

    vector<string> grid;
    string line;
    while (getline(cin, line))
        grid.push_back(line);

    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int i = 1; i < rows - 1; i++)
    {
        for (int j = 1; j < cols - 1; j++)
        {
            if (grid[i][j] == 'A')
            {
                int cnt = 0;
                if (grid[i - 1][j - 1] == 'M' && grid[i + 1][j + 1] == 'S')
                    cnt++;
                if (grid[i - 1][j + 1] == 'M' && grid[i + 1][j - 1] == 'S')
                    cnt++;
                if (grid[i - 1][j - 1] == 'S' && grid[i + 1][j + 1] == 'M')
                    cnt++;
                if (grid[i - 1][j + 1] == 'S' && grid[i + 1][j - 1] == 'M')
                    cnt++;
                
                if (cnt == 2)
                {
                    count++;
                }
            }
        }
    }

    cout << count << '\n';

    return 0;
}