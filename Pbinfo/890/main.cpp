#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[255], voc[] = "AEIOU";
    int ap[5] = {}, maxv = 0, poz;
    cin.get(s, 255);

    for (int i = 0; i < strlen(s); ++i)
    {
        for (int j = 0; j < 5; ++j)
            if (s[i] == voc[j] || s[i] == tolower(voc[j]))
            {
                ap[j]++;
                if (ap[j] > maxv)
                    maxv = ap[j], poz = j;
            }
    }

    cout << voc[poz];

    return 0;
}
