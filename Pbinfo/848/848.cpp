#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("paranteze1.in");
ofstream cout("paranteze1.out");

int main()
{
    int n, a[260] = {}, vfa = 0, ok;
    char s[260];

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        ok = 1, vfa = 0;
        cin >> s;

        for (int j = 0; j < strlen(s); ++j)
        {
            if (s[j] == '(')
                a[++vfa] = 1;
            else if (s[j] == ')' && !vfa)
                ok = 0; 
            else
                vfa--;
        }

        if (vfa)
            ok = 0;

        cout << ok << '\n';
    }

    return 0;
}