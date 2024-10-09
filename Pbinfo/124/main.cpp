#include <fstream>

using namespace std;

ifstream cin("permutari1.in");
ofstream cout("permutari1.out");

int st[14], viz[14], n, k;

void tipar(int k)
{
    for(int i = 1; i <= k; ++i)
        cout << st[i] << ' ';
    cout << '\n';
}

void back(int k)
{
    if (k == n + 1)
        tipar(k - 1);
    else
        for(int i = n; i >= 1; --i)
        {
            if (viz[i] == 0)
            {
                st[k] = i;
                viz[i] = 1;
                back(k + 1);
                viz[i] = 0;
            }
        }
}

int main()
{
    cin >> n;
    back(1);

    return 0;
}
