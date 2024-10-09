#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char nm[25], pr[25], v[] = "aeiouAEIOU", c[25];
    int n = 0;
    cin >> nm >> pr;

    for (int i = 0; i < strlen(pr); ++i)
    {
        if (!strchr(v, pr[i]))
            c[n] = pr[i], n++, c[n] = '\0';
    }

    cout << c << ' ' << nm;

    return 0;
}