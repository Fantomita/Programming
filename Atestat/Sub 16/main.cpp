#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int wordsStartingWithA(char s[])
{
    int cnt = 0;

    for (char *p = strtok(s, " "); p; p = strtok(nullptr, " "))
        if (p[0] == 'a' || p[0] == 'A')
            cnt++;

    return cnt;
}

int main()
{
    int vowels = 0;
    char s[100];
    
    fin.get(s, 100);

    for (int i = 0;  i < strlen(s); ++i)
    {
        cout << (char)toupper(s[i]);

        if (strchr("aeiouAEIOU", s[i]))
            vowels++;
    }
    cout << '\n' << vowels;

    fout << wordsStartingWithA(s);

    return 0;
}