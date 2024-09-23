#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int height, width;
int mat[1005][1005];
int treeX, treeY;

bool inmat(int x, int y, int maxHeight, int maxWidth)
{
    return x > 0 && x <= maxHeight && y > 0 && y <= maxWidth; 
}

bool isValid(int width, int height)
{
    string path;
    fin >> path;
    
    for (int x = 1; x <= height; ++x)
    {
        for (int y = 1; y <= width; ++y)
        {
            int X = x, Y = y;

            memset(mat, 0, sizeof(mat));
            mat[treeX][treeY] = -1;

            bool found = true;

            if (mat[X][Y] == -1)
                continue;
            
            mat[X][Y] = 1;

            for (int i = 0; i < path.size(); ++i)
            {
                switch (path[i])
                {
                    case 'W':
                        X--;
                        break;
                    case 'S':
                        X++;
                        break;
                    case 'D':
                        Y++;
                        break;
                    case 'A':  
                        Y--;
                        break;
                }

                if (!inmat(X, Y, height, width) || mat[X][Y] == -1)
                {
                    found = false;
                    break;
                }

                mat[X][Y]++;
                if (mat[X][Y] > 1)
                {
                    found = false;
                    break;
                }    
            }

            for (int i = 1; i <= height; ++i)
            {
                for (int j = 1; j <= width; ++j)
                {
                    if (mat[i][j] == 0)
                    {
                        found = false;
                        break;
                    }
                }
            }

            if (found)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int n;
    fin >> n;

    for (int i = 1; i <= n; i++)
    {
        int width, height;
        fin >> width >> height;

        for (int j = 1; j <= height; j++)
        {
           for (int k = 1; k <= width; k++)
            {
                char ch;
                fin >> ch;

                if (ch == 'X')
                {
                    treeX = j;
                    treeY = k;
                }
            }
        }

        fout << (isValid(width, height) ? "VALID" : "INVALID") << '\n'; 
    }

    return 0;
}