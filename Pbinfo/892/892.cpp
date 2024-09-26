#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[260], t[260] = {};
    int j = 0;
    cin.get(s, 260);

    for (int i = 0; i < strlen(s); ++i)
    {
        t[j++] = s[i];
        if (strchr("aeiou", s[i]))
            i += 2;
    }
    t[j] = '\0';

    cout << t;

    return 0;
}