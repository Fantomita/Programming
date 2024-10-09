#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[260];
    unsigned long long sum = 0, temp = 0;

    cin.get(s, 260);

    for (int i = 0; i < strlen(s); ++i)
    {
        temp = 0;
        while (isdigit(s[i]) && i < strlen(s))
        {
            temp = temp * 10 + (s[i] - '0');
            ++i;
        }
        sum += temp;
    }

    cout << sum;

    return 0;
}