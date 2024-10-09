#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

ifstream cin("permrep.in");
ofstream cout("permrep.out");

char c[10];
int viz[10], st[10], n;

int valid(int k)
{
    for (int i = 1; i <= k; ++i)
        if (c[st[i] - 1] == c[st[k] - 1] && st[i] > st[k])
            return 0;
    return 1;
}

void back(int k)
{
    if (k == n + 1)
    {
        for (int i = 1; i <= n; ++i)
            cout << c[st[i] - 1];
        cout << '\n';
    }
    else
        for (int i = 1; i <= n; ++i)
            if (!viz[i])
            {
                st[k] = i;
                viz[i] = 1;
                if (valid(k))
                    back(k + 1);
                viz[i] = 0;
            }
}

int main()
{
    cin >> c;
    n = strlen(c);
    sort(c, c + n);

    back(1);

    return 0;
}