#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[260];
    int nr = 0;

    cin.get(s, 2560);

    for (int i = 1; i <= strlen(s) - 2; ++i)
        if (strchr("aeiou", s[i]) && isalpha(s[i - 1]) && isalpha(s[i + 1]) && !strchr("aeiou", s[i - 1]) && !strchr("aeiou", s[i + 1]))
            ++nr;

    cout << nr;

    return 0;
}
