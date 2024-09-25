#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[260];
    cin.get(s, 260);

    for (int i = 0; i < strlen(s); ++i)
        if (i == 0 || i == strlen(s) - 1) s[i] -= 32;
        else if (isalpha(s[i]) && (s[i - 1] == ' ' || s[i + 1] == ' ')) s[i] -= 32;

    cout << s;

    return 0;
}
