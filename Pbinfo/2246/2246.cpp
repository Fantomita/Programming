#include <iostream>
#include <cstring>
using namespace std;

char s[100010];
int sol, n;

bool anagram(int p)
{
    int i, j;
    char ch, adobe[] = "bdaeo", t[6];
    for (i = 0; i < 5; ++i)
        t[i] = s[p + i];
    t[5] = 0;
    for (j = 0; j < 5; ++j)
    {
        ch = adobe[j];
        for (i = 0; i < 5 && ch != t[i]; ++i);
        if (i < 5) t[i] = '.';
        else
        {
            if (j < 2) ch = '+';
            else ch = '-';
            for (i = 0; i < 5 && ch != t[i]; ++i);
            if (i < 5) t[i] = '.';
            else
            {
                ch = '*';
                for (i = 0; i < 5 && ch != t[i]; ++i);
                if (i < 5) t[i] = '.';
                else return 0;
            }
        }
    }
    return 1;
}

void read()
{
    cin >> s;
    for (n = 0; s[n] != 0; ++n)
        if (s[n] >= 'A' && s[n] <= 'Z')
            s[n] += 32;
}

int main()
{
    read();
    int i, cnt;
    cnt = 0;
    for (i = 0; i < n - 4; ++i)
        cnt += anagram(i);
    cout << cnt;
    return 0;
}