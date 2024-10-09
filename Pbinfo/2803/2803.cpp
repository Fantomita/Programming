#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[260], t[260] = {}, c[260] = {};
    int p;
    
    cin >> p >> s;

    for (int i = 0; i < strlen(s) - p + 1; ++i)
    {
        strcpy(t, s);

        strcpy(c, t + i + p);
        strcpy(t + i, c);

        cout << t << '\n';
    }
    
    return 0;
}