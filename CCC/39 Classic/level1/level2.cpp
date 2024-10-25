#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int upmax, downmax, leftmax, rightmax;

void calculate_dimensions()
{
    string s;
    fin >> s;
    
    // Initialize the starting position
    int x = 0, y = 0;
    
    // Initialize the extremes to the starting position
    upmax = downmax = y;
    leftmax = rightmax = x;

    for (auto ch : s)
    {
        switch(ch)
        {
            case 'W':
                y++; // Move up
                break;
            case 'S':
                y--; // Move down
                break;
            case 'D':
                x++; // Move right
                break;
            case 'A':
                x--; // Move left
                break;
        }

        // Update the extremes
        upmax = max(upmax, y);
        downmax = min(downmax, y);
        leftmax = max(leftmax, x);
        rightmax = min(rightmax, x);
    }

    // Calculate the width and height of the board
    int width = leftmax - rightmax + 1;
    int height = upmax - downmax + 1;

    fout << width << ' ' << height << '\n';
}

int main()
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
        calculate_dimensions();

    return 0;
}
