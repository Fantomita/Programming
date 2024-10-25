#include <bits/stdc++.h>
using namespace std;

#define LEVEL string("level2")

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
                for (int col = 0; col + 3 < x; col += 3)
                {
                    if (deskID > maxDesks)
                        break;

                    gridRoom[row][col] = deskID;
                    gridRoom[row][col + 1] = deskID;
                    gridRoom[row][col + 2] = deskID;

                    deskID++;

                    cout << gridRoom[row][col] << " " << gridRoom[row][col + 1] << " " << gridRoom[row][col + 2] << " ";
                }
                cout << '\n';
            }
            cout << '\n';
        }
    }

    return 0;
}