#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("paranteze3.in");
ofstream cout("paranteze3.out");

int main()
{
    int n, i, ok, vf, st[260];
    char s[260];

    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        ok = 1;
        vf = 0;

        cin >> s;
        for (int j = 0; j < strlen(s) && ok; ++j)
        {
            if (s[j] == '(')
                st[++vf] = 1;
            if (s[j] == '[')
                st[++vf] = 2;
            
            if (s[j] == ')')
                if (st[vf] == 1)
                    vf--;
                else
                    ok = 0;
            if (s[j] == ']')
                if (st[vf] == 2)
                    vf--;
                else
                    ok = 0;        
        }
        if (vf < 0)
            ok = 0;

        cout << ok << '\n';
    }

    return 0;
}