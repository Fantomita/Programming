#include <fstream>

using namespace std;

ifstream cin("produscartezian1.in");
ofstream cout("produscartezian1.out");

int n, m, k, st[7];

void back(int k)
{
    if (k == m + 1)
    {
        for (int i = 1; i <= m; ++i)
            cout << st[i] << ' ';
        cout << '\n';
    }
    else
        for (int i = 1; i <= n; ++i)
        {
            st[k] = i;
            back(k + 1);
        }
}

int main()
{
    cin >> n >> m;
    back(1);
    return 0;
}
