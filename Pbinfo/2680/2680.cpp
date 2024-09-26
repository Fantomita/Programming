#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n;
    char s[260];
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin.get();
        cin.get(s, 260);
        for (int j = 0; j < strlen(s) - 1; ++j)
        {
            if (strchr(".,!?", s[j]))
            {
                char temp[260];
                strcpy(temp, s + j + 1);
                strcpy(s + j, temp);
                --j;
            }
        }
        cout << s << '\n';
    }
    return 0;
}