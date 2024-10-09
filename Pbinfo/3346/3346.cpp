#include <fstream>
#include <queue>

using namespace std;

ifstream cin("pestelee.in");
ofstream cout("pestelee.out");

const int dx[] = {0, 1, 0, -1},
          dy[] = {1, 0, -1, 0};

int n, m, a[505][505], c, cnt, b[505][505];
int xs, ys, xf, yf, p = 10007;
queue<pair<int, int>> q;

bool inside(int i, int j)
{
    return (i >= 1 && i <= n) && (j >= 1 && j <= m);
}

void lee()
{
    a[xs][ys] = b[xs][ys] = 1;
    q.push({xs, ys});

    while(!q.empty())
    {
        int i = q.front().first,
            j = q.front().second;

        for (int k = 0; k < 4; ++k)
        {
            int ii = i + dx[k],
                jj = j + dy[k];

            if (inside(ii, jj) && a[ii][jj] == 0)
            {
                a[ii][jj] = a[i][j] + 1;
                q.push({ii, jj});
            }
        }

        if (i == xs && j == ys)
            b[i][j] = 1;
        else
            b[i][j] = (b[i-1][j] % p + b[i][j-1] % p + b[i+1][j] % p + b[i][j+1] % p) % p;

        q.pop();
    }
}


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                a[i][j] = -1;
        }
    cin >> xs >> ys >> xf >> yf >> c;
    lee();
    
    //for (int i = 1; i <= n; ++i, cout << '\n')
        //for (int j = 1; j <= m; cout << a[i][j] << ' ', ++j);

    if (c == 1)
        cout << a[xf][yf];
    else
        cout << b[xf][yf];

    return 0;
}