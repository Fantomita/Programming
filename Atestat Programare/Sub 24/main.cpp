#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void printByRule(int n, char a[11][100])
{
    for (int i = 1; i <= n; ++i)
    {
        if (strlen(a[i]) < i)
            fout << ' ';
        else
            fout << a[i][i - 1];
    }
    fout << '.';
}

int main()
{
    int n, maxLength = 0, itMax;
    char a[11][100];

    fin >> n;
    fin.get();
    for (int i = 1; i <= n; ++i)
    {
        fin.getline(a[i], 100);

        for (int j = 0; j < strlen(a[i]); j++)
            cout << (char)tolower(a[i][j]);
        cout << ' ';

        if (strlen(a[i]) > maxLength)
        {
            maxLength = strlen(a[i]);
            itMax = i;
        }
    }
    cout << '\n' << a[itMax];

    printByRule(n, a);

    return 0;
}