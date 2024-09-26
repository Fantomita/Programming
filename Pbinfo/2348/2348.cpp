#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int sum = 0, n = 0;
    char s[205];
    
    cin.get(s, 205);

    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] != ' ' && (s[i] < 'A' || s[i] > 'Z') && strchr("aeiouAEIOU", s[i]) == 0)
        {
            n++;
            sum += s[i];
        }
    }

    cout << (char)(sum / n);

    return 0;
}