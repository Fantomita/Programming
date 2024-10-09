#include <iostream>
#include <cstring>

using namespace std;

char s[260], t[260], *p;
int i, j, maxv;

int main()
{
    cin.getline(s, 260);
    for (p = strtok(s, " "); p; p = strtok(NULL, " "))
    {
        int ok = 1;
        for (i = 0; i < strlen(p) - 1; ++i)
            for (j = i + 1; j < strlen(p); ++j)
                if (p[i] == p[j])
                        ok = 0;
            
        if (ok && strlen(p) > maxv)
        {
            maxv = strlen(p);
            strcpy(t, p);
        }
    }
    if (maxv != 0)
        cout << t;
    else
        cout << -1;
    return 0;
}