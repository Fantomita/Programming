#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[260], t[260] = {}, *p;
    int i, n, m = 0;
    cin.get(s, 260);
    for (i = 0; i < strlen(s); ++i)
    {
        n = strchr(s + i, " ") - (s + i);
        if (n == 3)
            t[m++] = '*';
        else
            for(j = i; j < i + n; ++j)
                t[m++] = s[j];
        i = i + n;
    }
    t[m] = '\0';
    cout << t;

    return 0;
}
