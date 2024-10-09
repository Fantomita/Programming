#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[255], t[255];
    cin.get(s, 255);
    cin.get();
    cin.get(t, 255);

    for (int i = 0; i < strlen(s); ++i)
    {
        int ok = 0;

        for (int j = 0; j < strlen(t) && ok == 0; ++j)
            if (s[i] == t[j])
                ok = 1;
        if (ok)
            cout << s[i];
    }

    return 0;
}