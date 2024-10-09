#include <bits/stdc++.h>

/* #define fin cin
#define fout cout */

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

int a[1500][1500];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int p, t;

    fin >> p >> t;

    while(t--)
    {
        int n;
        fin >> n;

        memset(a, 0, sizeof(a));

        for (int i = 1; i <= n; ++i)
        {
            string s;
            fin >> s;

            for (int j = 0; j < s.size(); ++j)
            {
                a[i][j + 1] = s[j] - '0';

                a[i][0] += a[i][j + 1];
                a[0][j + 1] += a[i][j + 1];
            }
        }

        if (p == 1)
        {
            bool isOk = 1;

            for (int i = 1; i <= n; ++i)
                if (a[i][0] != n / 2 || a[0][i] != n / 2)
                {
                    isOk = 0;
                    break;
                }      

            if (isOk)
                fout << "1\n";
            else
                fout << "0\n";
        }
    }


    return 0;
}