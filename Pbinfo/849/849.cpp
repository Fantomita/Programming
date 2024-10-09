#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("paranteze2.in");
ofstream cout("paranteze2.out");

int main()
{
    int i, vf = 0, maxv = 0;
    char s[260];

    cin >> s;
    for (i = 0; i < strlen(s); ++i)
    {
        if (s[i] == '(')
            vf++;
        else
            vf--;

        if (vf > maxv)
            maxv = vf;
    }

    cout << maxv;

    return 0;
}