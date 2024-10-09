#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void printSequences(char s[])
{
    for (int i = 0; i <= strlen(s) / 2; ++i)
    {
        fout << s << '\n';
        s[i] = s[strlen(s) - i - 1] = ' ';
    }
}


int main()
{
    char s[50];

    fin.get(s, 50);

    for (int i = 0; i < strlen(s); ++i)
        cout << (char)toupper(s[i]);
    cout << '\n';
    for (int i = 0; i < strlen(s); ++i)
        if (s[i] != ' ')
            cout << s[i];

    printSequences(strtok(s, " "));

    return 0;
}