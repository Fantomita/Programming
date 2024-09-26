#include <iostream>

using namespace std;

int a[10][10] = {}, x, i, j;

int existalin(int x, int i, int j)
{
    for(int k = 1 ; k <= 9 ; k++)
        if(x == a[i][k])
            return 0;
    return 1;
}

int existacol(int x, int i, int j)
{
    for(int k = 1 ; k <= 9 ; k++)
        if(x == a[k][j])
            return 0;
    return 1;
}

int existapatrat(int x, int i, int j)
{
    int lin = i, col = j;
    if(i % 3 == 0)
        lin = lin - 2;
    if(i % 3 == 2)
        lin--;
    if(j % 3 == 0)
        col = col - 2;
    if(j % 3 == 2)
        col--;
    for (int p = lin; p < lin + 3; p++)
        for (int q = col; q < col + 3; q++)
            if (a[p][q] == x)
                return 0;
    return 1;
}

int caut0(int &i, int &j)
{
    for (i = 1; i <= 9; ++i)
        for (j = 1; j <= 9; ++j)
            if (a[i][j] == 0)
                return 1;
    return 0;
}

void tipar()
{
    for (int i = 1; i <= 9; ++i, cout << '\n')
        for (int j = 1; j <= 9; cout << a[i][j] << ' ', ++j);
}

void back(int k, int i, int j)
{
    cout << '\n';
    tipar();
    cout << '\n';
    if (!caut0(i, j))
        tipar();
    else
        for(k = 1; k <= 9; ++k)
            if(!existalin(k, i, j) && !existacol(k, i, j) && !existapatrat(k, i, j))
            {
                a[i][j] = k;
                if (caut0(i, j))
                    back(k, i, j);
                a[i][j] = 0;
            }
}

int main()
{
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j)
            cin >> a[i][j];

    int i = 1, j = 1, k = 1;
    if (caut0(i, j))
        back(k, i, j);
    return 0;
}