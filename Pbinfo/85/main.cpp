#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("palindrom.in");
ofstream cout("palindrom.out");

int main()
{
    char s[200], v[] = "aeiou";
    bool ok = 0;

    cin.get(s, 200);

    for (int i = 0; i < strlen(s); ++i)
    {
        if (strchr(v, s[i]))
        {
            for (int j = strlen(s) + 1; j > i; j--)
                s[j] = s[j - 1];
            s[i + 1] = '*';
            i++;
            ok = 1;
        }
    }

    if(ok)
        cout << s;
    else
        cout << "FARA VOCALE";

    return 0;
}
