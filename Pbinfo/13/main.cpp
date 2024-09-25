#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[15], cpy[15];
    cin >> s;
    strcpy(cpy, s);

    for (int i = strlen(s) - 1; i >= 0; --i)
    {
        cout << cpy << '\n';
        cpy[i] = ' ';
    }

    for (int i = 0; i < strlen(s); ++i)
        cout << s + i << '\n';

    return 0;
}
