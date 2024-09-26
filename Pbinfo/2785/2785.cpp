#include <iostream>
#include <fstream>

#define NMAX 100005

using namespace std;

ifstream fin("galeti.in");
ofstream fout("galeti.out");

int n, from[NMAX], to[NMAX];
long long e;

void solve()
{
    int st = 1, dr = n, k = 0;

    while (st < dr)
    {
        int dif = dr - st + 1;

        if (e >= 2LL * dif - 3)
        {
            from[++k] = st + 1;
            to[k] = st;
            st++;
            e -= 1LL * dif - 1;
        }
        else
        {
            from[++k] = dr;
            to[k] = st;

            dr--;
            e -= 1LL;
        }
    }

    for (; k; k--)
        fout << from[k] << ' ' << to[k] << '\n';
}

int main()
{
    fin >> n >> e;
    solve();

    return 0;
}
