#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("prosir.in");
ofstream fout("prosir.out");

int main()
{
    char s[205];

    fin.get(s, 205);

    for (int i = 0; i < strlen(s) - 1; ++i)
        if (isalpha(s[i]) && s[i + 1] == ' ' || s[i + 1] == '.') s[i] = '5';

    fout << s;

    return 0;
}
