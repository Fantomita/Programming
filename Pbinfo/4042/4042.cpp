#include <iostream>

using namespace std;

void b16(long long n)
{
    if (n > 16)
    {
        b16(n / 16);
        if (n % 16 <= 9)
            cout << n % 16;
        else
            cout << (char)('A' + n % 16 - 10);
    }
    else
    {
        if (n % 16 <= 9)
            cout << n % 16;
        else
            cout << (char)('A' + n % 16 - 10);
    }
}

int main()
{
    long long n;
    cin >> n;
    b16(n);

    return 0;
}