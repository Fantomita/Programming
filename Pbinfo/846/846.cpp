#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[260], maxv[260] = {};
    cin >> s;

    for (int i = 0; i < strlen(s); ++i)
    {
        for(int j = i + 1; j < strlen(s); ++j)
        {
            char t[260] = {};
            strncpy(t, s + i, j - i + 1);
            t[j - i + 1] = '\0';
            if (strstr(s + i + 1, t) && (strlen(maxv) < strlen(t) || (strlen(maxv) == strlen(t) && strcmp(maxv, t) > 0)))
                strcpy(maxv, t);
        }
    }
    cout << maxv;
    return 0;
}