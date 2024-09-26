#include <iostream>
#include <cstring>
using namespace std;

struct cuv
{
    char c[130];
    int ok;
}b[130];

int main()
{
    char a[255], *p;
    int i, n = 0, j;

    cin.get(a, 255);
    cin.get();
    for (p = strtok(a, " "); p; p = strtok(NULL, " "))
    {
        for (i = 0; i < strlen(p); ++i)
            p[i] = tolower(p[i]);

        int g = 0;
        for (i = 1; i <= n; ++i)
            if (strcmp(b[i].c, p) == 0)
                g = 1;
        if (g == 0)
        {
            strcpy(b[++n].c, p);
            b[n].ok = 0;
        }
    }

    cin.get(a, 255);
    for (p = strtok(a, " "); p; p = strtok(NULL, " "))
    {
        for (i = 0; i < strlen(p); ++i)
            p[i] = tolower(p[i]);

        int g = 0;
        for (i = 1; i <= n; ++i)
            if (strcmp(b[i].c, p) == 0)
            {
                g = 1;
                b[i].ok = 1;
            }
    }

    for (i = 1; i <= n; ++i)
        for (j = i + 1; j <= n; ++j)
            if (strcmp(b[i].c, b[j].c) > 0 && b[i].ok == 1 && b[j].ok == 1)
                swap(b[i], b[j]);
    
    for (i = 1; i <= n; ++i)
        if (b[i].ok == 1)
            cout << b[i].c << '\n';
    return 0;
}