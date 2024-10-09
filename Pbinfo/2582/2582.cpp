#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[260], t[260];
    int i, j, ok;

    cin >> s;

    do
    {
        ok = 0;
        for (i = 0; i < strlen(s); ++i)
        {
            j = i;
            while(toupper(s[i]) == toupper(s[j]) && j < strlen(s))
                j++;
            if (j > i + 1)
            {
                strcpy(t, s + j);
                strcpy(s + i, t);
                ok = 1;
                i = strlen(s) - 1;
            }
        }
    } while (ok);
    
    cout << s;

    return 0;
}