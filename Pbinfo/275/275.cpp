#include <fstream>
#include <cstring>
#include <unordered_map>

using namespace std;

ifstream cin("perechivocale1.in");
ofstream cout("perechivocale1.out");

int main()
{
    char s[1000], voc[] = "aeiou";
    int i, j, maxv = 0, a[5][5] = {}, ok = 0;
    while(cin.get(s, 1000))
    {
        for (i = 0; i < strlen(s) - 1; ++i)
            if (strchr(voc, s[i]) && strchr(voc, s[i + 1]))
            {
                a[strchr(voc, s[i]) - voc][strchr(voc, s[i + 1]) - voc]++;
                if (a[strchr(voc, s[i]) - voc][strchr(voc, s[i + 1]) - voc] > maxv)
                    maxv = a[strchr(voc, s[i]) - voc][strchr(voc, s[i + 1]) - voc];
            }
                
    }

    for (i = 0; i < 5; ++i)
        for (j = 0; j < 5; ++j)
            if (a[i][j] == maxv)
            {
                ok = 1;
                cout << voc[i] << voc[j] << ' ';
            }
                
    if (!ok)
        cout << "NU";
        
    return 0;
}