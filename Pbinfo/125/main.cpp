#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("permutari2.in");
ofstream cout("permutari2.out");

int st[14], viz[14], a[14], n;

void tipar(int k)
{
    for (int i = 1; i <= k; ++i)
        cout << a[st[i]] << ' ';
    cout << '\n';
}

void back(int k)
{
    if (k == n + 1)
        tipar(k - 1);
    else
        for (int i = 1; i <= n; ++i)
            if (viz[i] == 0)
            {
                st[k] = i;
                viz[i] = 1;
                back(k + 1);
                viz[i] = 0;
            }

}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    back(1);

    return 0;
}
