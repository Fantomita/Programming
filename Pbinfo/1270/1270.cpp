#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[500];
    int i, nr, n = 0, p = 1;
    cin >> s;

    for (i = strlen(s) - 1; i >= 0; --i)
    {
        if (isalpha(s[i]))
            nr = s[i] - 'A' + 10;
        else
            nr = s[i] - '0';
        n = n + p * nr;
        p *= 16;
    }

    cout << n;
    
    return 0;
}