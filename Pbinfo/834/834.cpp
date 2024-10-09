#include <iostream>

using namespace std;

int elimcif(int n, int c)
{
    if (n == 0)
        return 0;
    else
    {
        if (n % 10 == c)
            return elimcif(n / 10, c);
        else
            return elimcif(n / 10, c) * 10 + n % 10;
    }
}

int main()
{
    cout << elimcif(1157, 1);
}