#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int poz[15], st[15], viz[15], n, k, m;
char a[15];

void anagrame(int k)
{
    if (k == n)
    {
        for (int i = 0; i < n; ++i)
            cout << a[st[i]];
        cout << '\n';
    }
    else
        for (int i = 0; i < n; ++i)
            if (!viz[i])
            {
                st[k] = i;
                viz[i] = 1;
                if (strchr("aeiou", a[i]) || i == k)
                    anagrame(k + 1);
                viz[i] = 0;
            }
}

int main()
{
    cin >> a;
    n = strlen(a);

    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (strchr("aeiou", a[i]) && strchr("aeiou", a[j]) && a[i] > a[j])
                swap(a[i], a[j]);

    anagrame(0);

    return 0;
}
