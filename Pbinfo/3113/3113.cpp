#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct cuv
{
    char cuv[5000];
    int f;
}a[5000];

char s[10005], *p;

bool compar(cuv st, cuv dr)
{
    return strcmp(st.cuv, dr.cuv) < 0;
}

int main()
{
    int n = 0, i;

    cin.get(s, 10005);
    for (p = strtok(s, " ,.!?"); p; p = strtok(NULL, " ,.!?:;"))
    {
        int ok = 0;
        for (i = 1; i <= n; ++i)
        {
            if (strcmp(a[i].cuv, p) == 0)
                ok = 1, a[i].f++;
        }
        if (!ok)
        {
            strcpy(a[++n].cuv, p),
            a[n].f = 1;
        }     
    }

    sort(a + 1, a + n + 1, compar);

    for (i = 1; i <= n; ++i)
        cout << a[i].cuv << ' ' << a[i].f << '\n';

    return 0;
}