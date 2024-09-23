#include <bits/stdc++.h>
using namespace std;

ifstream fin("cuvant2.in");
ofstream fout("cuvant2.out");

string s;
bool palindrom(int i, int j)
{
    for (; i <= j; i++, j--)
      if (s[i] != s[j]) return 0;

    return 1;
}

int main()
{
    int ma, secv;
    ma = secv = 0;

    int cnt = 0;
    fin >> s;

    while(s.size())
        for (int lenP = s.size(); lenP >= 0; lenP--)
            for (int yPal = s.size() - 1, xPal = yPal - lenP; xPal >= 0; yPal--, xPal--)
            {
                if (palindrom(xPal, yPal))
                {
                    ma = max(ma, lenP + 1);
                    cnt++;
                    s.erase(xPal,  lenP + 1);
                }
            }

    fout << cnt << " " << ma;
}