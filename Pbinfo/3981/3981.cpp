#include <iostream>

using namespace std;

int DivImpRec (int n)
{
    if (n % 2)
        return n;
    return DivImpRec(n / 2);
}

int main()
{
    cout << DivImpRec(24);

    return 0;
}