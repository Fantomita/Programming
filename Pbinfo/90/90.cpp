#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("vocmax.in");
ofstream cout("vocmax.out");

int main()
{
    int n, maxv = 0, v = 0;
    char s[255], temp[255];

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin.get();
        cin.get(s, 255);

        v = 0;
        for (int j = 0; j < strlen(s); ++j)
            if (strchr("aeiou", s[j])) v++;
        
        if(v > maxv)
            maxv = v, strcpy(temp, s);
    }

    cout << temp;

    return 0;
}