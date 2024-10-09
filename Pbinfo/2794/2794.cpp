#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[105], c[105], res[105], temp[105];
    int n = 0;

    cin >> s >> c;

    if (strlen(s) != strlen(c))
    {
        cout << "cod incorect";
        return 0;
    }

    for (int i = 0; i < strlen(c); ++i)
    {
        int cif = c[i] - '0';
        if (cif % 2 == 0)
        {
            strcpy(temp, res);
            strcpy(res + 1, temp);
            res[0] = s[i];
            n++;
        }
        else
        {
            res[n] = s[i];
            n++;
            res[n] = '\0';
        }
    }

    cout << res;

    return 0;
}