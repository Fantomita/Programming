#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[105], t[255];
    int j = 0;
    cin.get(s, 105);

    for (int i = 0; i < strlen(s); ++i)
    {
        t[j++] = s[i];
        if (strchr("aeiou", s[i]))
            t[j++] = s[i];
    }
    t[j] = '\0';

    cout << t;

    return 0;
}