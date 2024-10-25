#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int upmax, downmax, leftmax, rightmax;
int height, width; // New variables for height and width

void count()
{
    unordered_map<char, int> mp;

    string s;
    fin >> s;
    upmax = downmax = leftmax = rightmax = height = width = 0;
    for (auto ch : s)
    {
        switch(ch)
        {
            case 'W':
                height++;
                break;
            case 'S':
                height--;
                break;
            case 'D':
                width++;
                break;
            case 'A':
                width--;
                break;
        }

        // Update maximum values
        upmax = max(height, upmax);
        downmax = min(downmax, height);
        leftmax = max(leftmax, width);
        rightmax = min(rightmax, width);
    }

    // Calculate height and width
    height = abs(upmax - downmax);
    width = abs(leftmax - rightmax)''

    fout << "Height: " << height << ", Width: " << width << endl;
}

int main()
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
        count();

    return 0;
}
