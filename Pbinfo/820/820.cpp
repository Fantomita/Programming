#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n)
        return n * factorial(n - 1);
    else
        return 1;
}

int main()
{
    cout << factorial(4);

    return 0;
}