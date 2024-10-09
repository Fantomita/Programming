#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[11], v[] = "AEIOUaeiou";
    int p = -1, u = -1;

    cin >> s;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (p == -1 && strchr(v, s[i])) p = i;
        if (!strchr(v, s[i])) u = i;
    }

    if (p != -1 && u != -1)
    {
        swap(s[p], s[u]);
        cout << s;
    }
    else
        cout << "IMPOSIBIL";

    return 0;
}
