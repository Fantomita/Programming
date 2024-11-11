#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    bool ok = 1;
    char s[105];
    cin >> s;

    for (int i = 0; i < strlen(s) && ok; ++i)
        if (!(s[i] >= 'a' && s[i] <= 'z') || strchr("aeou", s[i]))
            ok = 0;

    cout << (ok ? "DA" : "NU");

    return 0;
}
