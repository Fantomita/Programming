#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[256];
    cin.get(s, 256);

    for (int i = 0; i < strlen(s); ++i)
        if (i == 0 || i == strlen(s) - 1) 
            s[i] -= 32;
        else if ((s[i] >= 'a' && s[i] <= 'z') && (s[i - 1] == ' ' || s[i + 1] == ' '))
            s[i] -= 32;

    cout << s;

    return 0;
}
