#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char c[260], *p, pal[15] = "";
    cin.get(c, 260);

    for (p = strtok(c, " "); p; p = strtok(NULL, " ,."))
    {
        bool ok = 1;

        for (int i = 0; i < strlen(p) / 2 && ok; ++i)
            if (p[i] != p[strlen(p) - i - 1])
                ok = 0;
                
        if (ok)
        {
            if (strlen(pal) == 0)
                strcpy(pal, p);
            else if(strcmp(p, pal) < 0)
                strcpy(pal, p);
        }
    }

    if (strlen(pal) == 0)
        cout << "IMPOSIBIL";
    else
        cout << pal;

    return 0;
}