#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void modifyWords(char s[70], char k)
{
    for (char *p = strtok(s, " "); p; p = strtok(nullptr, " "))
    {
        if (p[0] == 'M')
            p[0] = 'D';
        fout << p << ' ';
    }
}

int main()
{
    int words = 1;
    char s[70];

    fin.get(s, 70);

    for (int i = 0; i < strlen(s); ++i)
    {
        cout << (char)tolower(s[i]);
        if (s[i] == ' ')
            words++;
    }
    cout << '\n' << words;
    char k;
    cout << "\nLetter: ";
    cin >> k;
    modifyWords(s, k);

    return 0;
}