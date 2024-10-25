#include <bits/stdc++.h>
using namespace std;

#define LEVEL string("level1")

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
            int x, y;
            cin >> x >> y;

            cout << (x / 3) * y << '\n';
        }
    }

    return 0;
}