#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a[260] = {}, vfa = 0, k = 0;
    char s[260];

    cin >> s;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == '(')
        {
            k++;
            a[++vfa] = k;
        }
        else
        {
            cout << a[vfa] << ' ';
            vfa--;
        }
    }

    return 0;
}