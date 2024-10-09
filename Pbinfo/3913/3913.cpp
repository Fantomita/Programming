#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int st[11], viz[11], n, k, m;
char c[11];

int valid(int k)
{
    if (k > 1 && strchr("aeiou", c[st[k - 1] - 1]) && strchr("aeiou", c[st[k] - 1]))
        return 0;
    if (k > 1 && st[k - 1] > st[k])
        return 0;
    return 1;
}

void back(int k)
{
    if (k > m)
    {
        if (strchr("aeiou", c[st[k - 1] - 1] == 0))
        {
            for (int i = 1; i < k; ++i)
                cout << c[st[i] - 1];
            cout << '\n';
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (viz[i] == 0)
        {
            st[k] = i;
            viz[i] = 1;
            if (k <= n && valid(k))
                back(k + 1);
            viz[i] = 0;
        }
    }
}

int main()
{
    cin >> c >> m;
    n = strlen(c);
    sort(c, c + n);
    back(1);
    return 0;
}