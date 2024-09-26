#include <iostream>

using namespace std;

void sumcif(int n, int& s)
{
    if (n == 0)
        s = 0;
    if (n)
    {
        sumcif(n / 10, s);
        s += n % 10;
    }
}

int main()
{
    cout << sumcif(2051);

    return 0;
}