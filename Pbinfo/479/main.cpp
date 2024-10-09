#include <fstream>

using namespace std;

ifstream cin("lantmaxim1.in");
ofstream cout("lantmaxim1.out");

int a[21][21], stv[21], n, q, x, y, m, viz[21], ok, maxv, s[21];

void back(int k)
{
    if(k > 2 && k <= n + 1 && stv[k - 1] == q)
    {
        if(k - 1 > maxv)
        {
            maxv = k - 1;
            for(int i = 1; i < k; i++)
                s[i] = stv[i];
        }
    }

    for(int i = 1; i <= n; i++)
        if(viz[i] == 0)
        {
            stv[k] = i;
            viz[i] = 1;
            if(k == 1 || k > 1  && a[stv[k]][stv[k - 1]] == 1)
                back(k + 1);
            viz[i] = 0;
        }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    cin >> p>> q;

    stiv[1] = p;
    viz[p] = 1;

    back(2);

    for(int i = 1; i <= maxv; i++)
        cout<< s[i] <<" ";
    return 0;
}
