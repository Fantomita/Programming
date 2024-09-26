#include <iostream>

using namespace std;

int cifmax(int n)
{
    if (n <= 9)
        return n;
    else
        return max(cifmax(n / 10), n % 10);
}


int main()
{
    cout << cifmax(90008);
}