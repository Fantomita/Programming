#include <fstream>


using namespace std;
ifstream cin("componenteconexe2.in");
ofstream cout("componenteconexe2.out");

int a[101][101], n, nrc = 1, viz[101], nrm, m;
void df(int x)
{
    viz[x] = nrc;
    for (int i = 1; i <= n; i++)
        if (a[x][i] == 1 && viz[i] == 0)
            df(i);
}
int main()
{
    int x, y, ok;
    cin >> n;
    while (cin >> x >> y)
    {
        if (a[x][y] == 0)
            m++;
        a[x][y] = a[y][x] = 1;
    }

    do
    {
        ok = 0;
        for (int i = 1; i <= n; i++)
            if (viz[i] == 0)
            {
                df(i);
                for (int j = 1; j <= n; j++)
                    if (viz[j] == nrc)
                        nrm++;
                nrc++;
                ok = 1;
                nrm--;
            }
    } while (ok == 1);
    cout << m - nrm;
    return 0;
}