#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void printAnagrams(char s[])
{
    char a[100][100], s1[100], s2[100];
    int n = 0;

    for (char *p = strtok(s, " "); p; p = strtok(nullptr, " "))
        strcpy(a[++n], p);


    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            int f1[27] = {}, f2[27] = {};

            strcpy(s1, a[i]);
            strcpy(s2, a[j]);

            if (strlen(s1) != strlen(s2))
                continue;

            for (int k = 0; k < strlen(s1); ++k)
            {
                f1[(char)toupper(s1[k]) - 'A' + 1]++;
                f2[(char)toupper(s2[k]) - 'A' + 1]++;
            }

            int ok = 1;
            for (int k = 1; k <= 26; ++k)
            {
                //cout << f1[k] << ' ' << f2[k] << '\n';
                if (f1[k] != f2[k])
                    ok = 0;
            }
            if (ok)
                fout << a[i] << ' ' << a[j] << '\n';
        }
}

int main()
{
    char s[100];

    fin.get(s, 100);

    for (int i = 0; i < strlen(s); ++i)
        cout << (char)toupper(s[i]);
    cout << '\n';
    for (int i = 0; i < strlen(s); ++i)
        if (s[i] != ' ')
            cout << s[i];
    cout << '\n';
    printAnagrams(s);

    return 0;
}