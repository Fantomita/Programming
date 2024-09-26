#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char c[260], *p, temp[15] = "";
    cin.get(c, 260);

    for (p = strtok(c, " "); p; p = strtok(NULL, " "))
    {
        bool ok = 1;

        for (int i = 0; i < strlen(p) && ok; ++i)
            if (!isdigit(p[i]))
                ok = 0;
                
        if (ok && p[0] > temp[0])
            strcpy(temp, p);
    }

    if (strlen(temp) == 0)
        cout << "nu exista";
    else
        cout << temp;

    return 0;
}