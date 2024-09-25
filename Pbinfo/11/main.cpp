#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[25];
    cin.get(s, 25);

    for (int i = 0; i < strlen(s); ++i)
        if (strchr("aeiou", s[i]))
            s[i] -= 32;

    cout << s;

    return 0;
}
