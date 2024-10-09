#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s1[35], s2[35], res[35], v[] = "aeiou";
    int n = 0;

    cin >> s1 >> s2;

    for (int i = 0; i < strlen(s1); ++i)
    {
        if (strchr(v, s1[i]) && strchr(v, s2[i]))
            res[n] = '*', n ++, res[n] = '\0';
        else if (!strchr(v, s1[i]) && !strchr(v, s2[i]))
            res[n] = '#', n ++, res[n] = '\0';
        else
            res[n] = '?', n ++, res[n] = '\0';  
    }

    cout << res;

    return 0;
}