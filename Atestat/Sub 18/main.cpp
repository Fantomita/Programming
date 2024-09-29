#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void printWords(char s[])
{
    for (char *p = strtok(s, " "); p; p = strtok(nullptr, " "))
        cout << p << '\n';
}

int main()
{
    int digits = 0;
    char s[100];

    fin.get(s, 100);

    for (int i = 0; i < strlen(s); ++i)
    {
        cout << (char)tolower(s[i]);

        if (isdigit(s[i]))
            digits++;
    }
    cout << '\n';

    printWords(s);
    fout << digits;

    

    return 0;
}