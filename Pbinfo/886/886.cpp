#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int nr = 0, i = 0, lmax = 0, poz;
    char s[260];

    cin >> s;
    for (i = 0; i < strlen(s); ++i)
    {
        if(strchr("aeiou", s[i]) == 0)
            ++nr;
        else
            nr = 0;
        if (nr >= lmax)
            lmax = nr, poz = i - lmax + 1;
    }

    for (i = poz; i < poz + lmax; ++i)
        cout << s[i];

    return 0;
}