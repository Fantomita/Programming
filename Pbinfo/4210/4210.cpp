#include <iostream>

using namespace std;

int FCrescRec(int n)
{
    if (n <= 9)
        return 1;
    if (n % 10 <= n / 10 % 10)
        return FCrescRec(n / 10);   
    return 0;
}

int main()
{
    cout << FCrescRec(975311);

    return 0;
}