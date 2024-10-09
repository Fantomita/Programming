#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[105], acron[105];
    int k = 0;
    cin.get(s, 105);

    for (int i = 0; i < strlen(s); ++i)
        if (isupper(s[i]) && (i == 0 || s[i - 1] == ' ')) acron[k++] = s[i];
    acron[k] = '\0';

    cout << acron;

    return 0;
}
