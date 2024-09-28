#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

int numberOfWords(char s[])
{
    int nb = 0;
    char *p;

    for (p = strtok(s, " "); p; p = strtok(nullptr, " "))
        nb++;

    return nb;
}

int main()
{
    int consonants = 0;
    char s[250];
    fin.get(s, 250);

    for (int i = 0; i < strlen(s); ++i)
    {
        cout << (char)toupper(s[i]);
        if (!(strchr("aeiouAEIOU", s[i])) && s[i] != ' ')
            consonants++;
    }
    cout << '\n' << consonants << '\n';

    fout << numberOfWords(s);
    return 0;
}