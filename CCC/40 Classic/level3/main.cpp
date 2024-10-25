#include <bits/stdc++.h>
using namespace std;

#define LEVEL string("level3")

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

            vector<vector<int>> gridRoom(y, vector<int>(x, 0));

            int deskID = 1;

            for (int row = 0; row < y && deskID <= maxDesks; ++row)
            {
                for (int col = 0; col + 3 <= x; col += 3)
                {
                    if (deskID > maxDesks)
                    {
                        break;
                    }

                    gridRoom[row][col] = deskID;
                    gridRoom[row][col + 1] = deskID;
                    gridRoom[row][col + 2] = deskID;

                    deskID++;
                }
            }

            for (int col = 0; col < x && deskID <= maxDesks; ++col)
            {
                for (int row = 0; row + 3 <= y; ++row)
                {
                    if (deskID > maxDesks)
                    {
                        break;
                    }

                    if (gridRoom[row][col] != 0 || gridRoom[row + 1][col] != 0 || gridRoom[row + 2][col] != 0)
                    {
                        continue;
                    }

                    gridRoom[row][col] = deskID;
                    gridRoom[row + 1][col] = deskID;
                    gridRoom[row + 2][col] = deskID;

                    deskID++;
                }
            }

            for (auto &row : gridRoom)
            {
                for (int desk : row)
                {
                    cout << desk << " ";
                }
                cout << '\n';
            }
            cout << '\n';
        }
    }

    return 0;
}