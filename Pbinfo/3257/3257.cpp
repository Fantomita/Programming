#include <iostream>
#include <cstring>

using namespace std;

int value(char c)
{
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
}

bool is_valid(char s[])
{
    for (int i = 0; i < strlen(s); ++i)
    {
        int nc = 0;
        while (s[i] == s[i + 1])
        {
            nc++;
            ++i;
        }
        nc++;
        cout << s[i] << ' ' << nc << '\n';
        if (nc > 3 || (nc > 1 && (value(s[i]) == 5 || value(s[i] == 50 || value(s[i]) == 500 || value(s[i]) < value(s[i + 1])))))
            return false;
        if ((s[i] == 'D' && s[i + 1] == 'M') || (s[i] == 'L' && s[i + 1] == 'C'))
            return false;
    }
    return true;
}

int roman_to_int(char s[])
{
    int sum = 0;
    for (int i = 0; i < strlen(s) - 1; ++i)
    {
        int v1 = value(s[i]);

        if (i + 1 < strlen(s))
        {
            int v2 = value(s[i + 1]);

            if (v1 >= v2)
                sum += v1;
            else
                sum = sum + v2 - v1, ++i;
        }
        else
            sum = sum + v1;
    }
    return sum;
}

int main()
{
    char s[20];
    cin >> s;
    if (is_valid(s))
        cout << roman_to_int(s);
    else
        cout << "Numar invalid";
    return 0;
}