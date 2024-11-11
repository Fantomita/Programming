#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[21];
    cin.get(s, 21);

    for (int i = 0; i < strlen(s); ++i)
    {
        if (strchr("aeiou", s[i]))
            s[i] = s[i] - 32;
    }

    cout << s;

    return 0;
}
