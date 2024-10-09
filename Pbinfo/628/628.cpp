#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("cub1.in");
ofstream fout("cub1.out");

struct coords
{
    int i, j, k;
};

const int di[] = {1, -1, 0, 0, 0, 0}, dj[] = {0, 0, 1, 0, -1, 0}, dk[] = {0, 0, 0, 1, 0, -1}, binary[] = {1, 2, 4, 8, 16, 32};
int n, a[105][105][105], viz[105][105][105], maxp, c;
coords maxv;

void read()
{
    fin >> c >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
            {
                fin >> a[i][j][k];

                int nc = 0;
                for (int d = 0; d < 6; ++d)
                    if (a[i][j][k] & binary[d])
                        nc++;
                
                if (nc > maxp)
                {
                    maxp = nc;
                    maxv.i = i;
                    maxv.j = j;
                    maxv.k = k;
                }
            }
}

bool inMatrix(int i, int j, int k)
{
    return i >= 1 && i <= n && j >= 1 && j <= n && k >= 1 && k <= n;
}

void restorePath(int i, int j, int k)
{
    if (i == 1 && j == 1 && k == 1)
        return;
    for (int d = 0; d < 6; ++d)
    {
        int ii = i + di[d], jj = j + dj[d], kk = k + dk[d];
        //cout << ii << ' ' << jj << ' ' << kk << '\n';
        if(inMatrix(ii, jj, kk) && viz[ii][jj][kk] == viz[i][j][k] - 1)
        {
            restorePath(ii, jj, kk);
            fout << ii << ' ' << jj << ' ' << kk << '\n';
            return;
        }
    }
}

void lee()
{
    queue<coords> q;

    viz[1][1][1] = 1;
    q.push({1, 1, 1});

    while(!q.empty())
    {
        int i = q.front().i, j = q.front().j, k = q.front().k;

        for (int d = 0; d < 6; ++d)
        {
            int ii = i + di[d], jj = j + dj[d], kk = k + dk[d];

            if (a[i][j][k] & binary[d] && inMatrix(ii, jj, kk) && (viz[ii][jj][kk] == 0))
            {
                viz[ii][jj][kk] = viz[i][j][k] + 1;
                q.push({ii, jj, kk});

                if (ii == n && jj == n && kk == n)
                {
                    fout << viz[ii][jj][kk] << '\n';
                    restorePath(n, n, n);
                    fout << n << ' ' << n << ' ' << n;
                    return;
                }
            }
        }
        q.pop();
    }
}

int main()
{
    read();
    if (c == 1)
    {
        fout << maxv.i << ' ' << maxv.j << ' ' << maxv.k << '\n';
        return 0;
    }
    else
    {
        lee();
    }
    return 0;
}