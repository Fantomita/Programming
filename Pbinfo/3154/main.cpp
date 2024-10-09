#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int poz[15], st[15], viz[15], n, k, m;
char a[15], aux[15], t[15];

void anagrame(int k)
{
    if (k == n)
    {
        int j = 0;
        for (int i = 0; i < m; ++i)
            if (poz[i])
                cout << aux[i];
            else
                cout << a[st[j++]];
        cout << '\n';
    }

    else
        for (int i = 0; i < n; ++i)
            if (viz[i] == 0)
            {
                st[k] = i;
                viz[i] = 1;
                anagrame(k + 1);
                viz[i] = 0;
            }
}

int main()
{
    cin >> a;
    m = strlen(a);
    strcpy(aux, a);
    int j = 0;
    for (int i = 0; i < strlen(a); ++i)
        if (strchr("aeiou", a[i]))
        {
            poz[j] = 1;
            j++;
            strcpy(t, a + i + 1);
            strcpy(a + i, t);
            i--;
        }
        else
            j++;
    n = strlen(a);
    sort(a, a + strlen(a));
    anagrame(k);

    return 0;
}
