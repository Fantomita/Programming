#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char c[260], *p;
    cin.get(c, 260);

    for (p = strtok(c, " "); p; p = strtok(NULL, " "))
    {
        bool ok = 1;

        for (int i = 0; i <= strlen(p) && ok; ++i)
            if (!strchr("aeiou", p[i]))
                ok = 0;
                
        if (ok)
            cout << p << '\n';
    }

    return 0;
}