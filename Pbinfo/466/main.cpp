#include <fstream>
#include <cmath>

using namespace std;

ifstream cin("gengraf.in");
ofstream cout("gengraf.out");

int n, k, a[7][7], st[50];

void back(int k)
{
    if (k == n * (n - 1) / 2 + 1)
    {
        int p = 1;
        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j <= n; ++j)
                a[i][j] = a[j][i] = st[p++];

        for (int i = 1; i <= n; ++i, cout << '\n')
            for (int j = 1; j <= n; cout << a[i][j] << ' ', ++j);
        cout << '\n';
    }
    else
        for (int i = 0; i <= 1; ++i)
        {
            st[k] = i;
            if (k <= n * (n - 1) / 2)
                back(k + 1);
        }
}

int main()
{
    cin >> n;
    cout << pow(2.0, n * (n - 1) / 2) << '\n';
    back(1);
    return 0;
}
