#include <bits/stdc++.h>
using namespace std;

#define LEVEL string("level4")

int main()
{
    for (int file = 0; file <= 5; ++file)
    {
        string inputFile = LEVEL + "_" + to_string(file) + ".in";
        string outputFile = LEVEL + "_" + to_string(file) + ".out";

        if (file == 0)
        {
            inputFile = LEVEL + "_example.in";
            outputFile = LEVEL + "_example_mine.out";
        }

        ifstream cin(inputFile);
        ofstream cout(outputFile);

        int N;
        cin >> N;

        for (int i = 0; i < N; ++i)
        {
            int x, y, maxDesks;
            cin >> x >> y >> maxDesks;

            vector<vector<int>> desks(y, vector<int>(x, 0));

            for (int col = 0; col < x; col += 2)
            {
                for (int row = 0; row + 3 <= y; row += 4)
                {
                    if (maxDesks == 0)
                    {
                        break;
                    }

                    desks[row][col] = 1;
                    desks[row + 1][col] = 1;
                    desks[row + 2][col] = 1;

                    maxDesks--;
                }

                if (maxDesks == 0)
                {
                    break;
                }
            }

            for (int col = 0; col + 3 <= x; col += 4)
            {
                if (maxDesks == 0)
                {
                    break;
                }

                if (desks[y - 1][col] == 0 && desks[y - 1][col + 1] == 0 && desks[y - 1][col + 2] == 0)
                {
                    desks[y - 1][col] = 1;
                    desks[y - 1][col + 1] = 1;
                    desks[y - 1][col + 2] = 1;

                    maxDesks--;
                }
            }

            for (auto &row : desks)
            {
                for (int desk : row)
                {
                    cout << (desk == 1 ? "X" : ".");
                }
                cout << '\n';
            }
            cout << '\n';
        }
    }

    return 0;
}