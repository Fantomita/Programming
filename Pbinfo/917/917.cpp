#include <iostream>

using namespace std;

void cmmdc(int a, int b, int& r)
{
    if (b == 0)
        r = a;
    else
        cmmdc(b, a % b, r);
}

int main()
{
    cout << cmmdc(18, 24);

    return 0;
}