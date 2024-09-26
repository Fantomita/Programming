#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("capslock.in");
ofstream cout("capslock.out");

int main()
{
    int i, ok = 0;
    char s[260];
    
    cin.get(s, 260);

    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == '#')
            if (!ok) ok = 1;
            else ok = 0;
        else
            if (ok)
                cout << (char)toupper(s[i]);
            else
                cout << (char)tolower(s[i]); 
    }

    return 0;
}