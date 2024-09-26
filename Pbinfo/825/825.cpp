#include <iostream>

using namespace std;

int cifmin(int n)
{
    int minc;

    if (n <= 9)
        return n;
    else
    {
        minc = cifmin(n / 10);
        if (minc > n % 10)
            return n % 10;
        else
            return minc;
    }
}


int main()
{
    cout << cifmin(1234);
}