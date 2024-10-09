#include <iostream>

using namespace std;

int sumcif(int n)
{
    if (n == 0)
        return 0;
    if (n)
        return sumcif(n / 10) + n % 10;
}

int main()
{
    cout << sumcif(2051);

    return 0;
}