#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[1000005];
    int n, x;

    cin >> s >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;

        char temp[1005];
        strncpy(temp, s, x);

        if (x % 2)
            reverse(temp, temp + x);

        strncat(s, temp, x);
    }

    cout << s;

    return 0;
}