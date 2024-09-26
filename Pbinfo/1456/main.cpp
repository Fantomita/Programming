#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[105];
    bool ok1 = 1, ok2 = 0;
    cin >> s;

    for (int i = 0; i < strlen(s); ++i)
    {
        if (strchr("aeou", s[i])) ok1 = 0;
        else if (isalpha(s[i]) && s[i] != 'i') ok2 = 1;
    }

    if (ok1 && ok2) cout << "DA";
    else cout << "NU";

    return 0;
}
