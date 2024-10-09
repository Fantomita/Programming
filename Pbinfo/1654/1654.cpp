#include <iostream>
#include <cstring>

using namespace std;

int nr_vocale(char s[])
{
    char c = s[strlen(s) - 1];
    s[strlen(s) - 1] = '\0';
    if (strlen(s) == 0)
        if (strchr("aeiouAEIOU", c))
            return 1;
        else
            return 0;
    else
        if (strchr("aeiouAEIOU", c))
            return 1 + nr_vocale(s);
        else
            return nr_vocale(s);
}

int main()
{
    char s[10005];
    cin.get(s, 10005);
    cout << nr_vocale(s);
}