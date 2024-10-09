#include <fstream>

using namespace std;

ifstream cin("soarece1.in");
ofstream cout("soarece1.out");

int n, m, is, ib, js, jb, a[11][11], b[11][11], k = 1, nr, ok = 1, ok1;
char ch;

int inside(int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

void back(int k, int i, int j)
{
    if (i == ib && j == jb && ok)
    {
        a[i][j] = k, ok = 0;

        for (int i = 1; i <= n; ++i, cout << '\n')
            for (int j = 1; j <= m; ++j)
            {
                if (a[i][j] == -1)
                    cout << "0 ";
                else
                    cout << a[i][j] << ' ';
            }
    }
    else if (inside(i, j) && ok)
    {
        a[i][j] = k;
        if (!a[i - 1][j])
            back(k + 1, i - 1, j);
        if (!a[i][j + 1])
            back(k + 1, i, j + 1);
        if (!a[i + 1][j])
            back(k + 1, i + 1, j);
        if (!a[i][j - 1])
            back(k + 1, i, j - 1);
        a[i][j] = 0;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin.get();
        for (int j = 1; j <= m; ++j)
        {
            cin >> ch;
            if (ch =='#')
                a[i][j] = -1;
            else if (ch == 'B')
            {
                ib = i;
                jb = j;
            }
            else if (ch == 'S')
            {
                is = i;
                js = j;
            }
        }
    }

    back(k, is, js);

    if (ok)
        for (int i = 1; i <= n; ++i, cout << '\n')
            for (int j = 1; j <= m; ++j)
                cout << "0 ";

    return 0;
}
