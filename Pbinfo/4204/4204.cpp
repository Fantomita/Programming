#include <fstream>

using namespace std;

ifstream cin("estearbore.in");
ofstream cout("estearbore.out");

int v[101], a[101][101] = {}, n;

void df(int x)
{
    v[x] = 1;
    for (int k = 1; k <= n; k++)
        if (a[x][k] != 0 && v[k] == 0)
            df(k);
}

int main()
{
    int x, y, ok = 1;

    cin >> n;
    while (cin >> x >> y)
    {
        a[x][y] = a[y][x] = 1;
    }

    df(1);

    for (int i = 1; i <= n; i++)
        if (!v[i])
            ok = 0;


    if (ok)
        cout << "DA";
    else
        cout << "NU";

    return 0;
}