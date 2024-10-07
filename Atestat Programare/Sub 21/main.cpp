#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

bool isPalindrom(char s[])
{
    for (int i = 0; i < strlen(s); ++i)
        if (toupper(s[i]) != toupper(s[strlen(s)- i - 1]))
            return false;
    return true;
}

int main()
{
    char s[100];

    fin.get(s, 100);

    for (int i = 0; i < strlen(s); ++i)
        cout << (char)tolower(s[i]);
    cout << '\n';
    for (int i = 0; i < strlen(s); ++i)
        if (s[i] != ' ')
            cout << s[i];

    for (char *p = strtok(s, " "); p; p = strtok(nullptr, " "))
    {
        if (isPalindrom(p))
            fout << p << '\n';
    }
    return 0;
}