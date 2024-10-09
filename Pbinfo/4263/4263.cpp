#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("ifelse.in");
ofstream cout("ifelse.out");

int main()
{
    int n, vf, nrcuv, nr;
    char s[40005], *p;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin.get();
        cin.get(s, 40005);

        vf = 0;
        nr = 0;
        nrcuv = 0;

        for (p = strtok(s, " "); p; p = strtok(NULL, " "))
        {
            nrcuv++;
            if (strcmp(p, "if") == 0)
                vf++;
            else
                vf--;
            if (vf < 0)
            {
                ++nr;
                vf = 1;
            }
        }

        if (nrcuv % 2 == 1)
            cout << -1 << '\n';
        else
            cout << nr + vf / 2 << '\n';
    }

    return 0;
}