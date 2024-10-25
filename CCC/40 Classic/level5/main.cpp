#include <bits/stdc++.h>
using namespace std;

#define LEVEL string("level5")

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
    }

    return 0;
}