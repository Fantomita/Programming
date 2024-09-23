#include <bits/stdc++.h>

using namespace std;

ifstream fin("fractal.in");
ofstream fout("fractal.out");

int k, x, y;

int fastExp(int a, int p)
{
    if (a == 0)
        return 0;
    if (p <= 0)
        return 1;

    int aux = fastExp(a, p / 2);

    if (p % 2 == 0)
        return aux * aux;
    return aux * aux * a;
}

int rotatedir(int rotatedState, int direction)
{
     return (rotatedState + direction + 4) % 4;
}

int addSum(int x, int y, int k)
{
    //fout << "RotatedState: " << x << "\nCadranul: " << y + 1 << '\n';

    if (x == 0)
    {
        if (y == 0)
            return 0;
        if (y == 1)
            return fastExp(2, 2 * k - 2);
        if (y == 2)
            return fastExp(2, 2 * k - 1);
        if (y == 3)
            return 3 * fastExp(2, 2 * k - 2);
    }
    if (x == 1)
    {
        if (y == 2)
            return 0;
        if (y == 1)
            return fastExp(2, 2 * k - 2);
        if (y == 0)
            return fastExp(2, 2 * k - 1);
        if (y == 3)
            return 3 * fastExp(2, 2 * k - 2);
    }
    if (x == 2)
    {
        if (y == 2)
            return 0;
        if (y == 3)
            return fastExp(2, 2 * k - 2);
        if (y == 0)
            return fastExp(2, 2 * k - 1);
        if (y == 1)
            return 3 * fastExp(2, 2 * k - 2);
    }
    if (x == 3)
    {
        if (y == 0)
            return 0;
        if (y == 3)
            return fastExp(2, 2 * k - 2);
        if (y == 2)
            return fastExp(2, 2 * k - 1);
        if (y == 1)
            return 3 * fastExp(2, 2 * k - 2);
    }
}

int rotatedRotateDirection(int x, int y)
{
    if (x == 0)
    {
        if (y == 0)
            return -1;
        if (y == 1)
            return 0;
        if (y == 2)
            return 0;
        if (y == 3)
            return 1;
    }
    if (x == 1)
    {
        if (y == 0)
            return 0;
        if (y == 1)
            return 0;
        if (y == 2)
            return 1;
        if (y == 3)
            return -1;
    }
    if (x == 2)
    {
        if (y == 0)
            return 0;
        if (y == 1)
            return 1;
        if (y == 2)
            return -1;
        if (y == 3)
            return 0;
    }
    if (x == 3)
    {
        if (y == 0)
            return 1;
        if (y == 1)
            return -1;
        if (y == 2)
            return 0;
        if (y == 3)
            return 0;
    }
}

int solve(int x1, int y1, int x2, int y2, int k, int rotatedState)
{
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;

    if (k == 0)
        return 0;

    if (x <= midX && y <= midY)
    {
        
        int sum = addSum(rotatedState, 0, k);
        //fout << sum << '\n';
        return sum + solve(x1, y1, midX, midY, k - 1, rotatedir(rotatedState, rotatedRotateDirection(rotatedState, 0)));
    }
    else if (x > midX && y <= midY)
    {   
        int sum = addSum(rotatedState, 1, k);
        //fout << sum << '\n';
        return sum + solve(midX + 1, y1, x2, midY, k - 1, rotatedir(rotatedState, rotatedRotateDirection(rotatedState, 1)));
    }
    else if (x > midX && y > midY)
    {
        int sum = addSum(rotatedState, 2, k);
        //fout << sum << '\n';
        return sum + solve(midX + 1, midY + 1, x2, y2, k - 1, rotatedir(rotatedState, rotatedRotateDirection(rotatedState, 2)));
    }
    else
    {
        int sum = addSum(rotatedState, 3, k);
        //fout << sum << '\n';
        return sum + solve(x1, midY + 1, midX, y2, k - 1, rotatedir(rotatedState, rotatedRotateDirection(rotatedState, 3)));
    }
}

int main()
{
    fin >> k >> y >> x;

    int coord = fastExp(2, k);

    fout << solve(1, 1, coord, coord, k, 0);
    
/*     int mat[coord + 5][coord + 5] = {};
    for (int i = 1; i <= coord; ++i)
        for (int j = 1; j <= coord; ++j)
        {
            x = i;
            y = j;
            mat[i][j] = solve(1, 1, coord, coord, k, 0);
        } */

    //for (int i = 1; i <= coord; ++i, fout << '\n')
        //for (int j = 1; j <= coord; fout << mat[i][j] << ' ', ++j);
    
    return 0;
}