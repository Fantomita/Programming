#include <iostream>

using namespace std;

int CifDiv3Rec(int n)
{
    if (n > 9)
    {
        if ((n % 10) % 3 == 0)
            return 1 + CifDiv3Rec(n / 10);
        else if (n)
            return CifDiv3Rec(n / 10);
    }
    else if (n >= 0 && n % 3 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    cout << CifDiv3Rec(2009376);

    return 0;
}