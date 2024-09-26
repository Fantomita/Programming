#include <iostream>

using namespace std;

int cmmdc(int a, int b)
{
    if (b)
        return cmmdc(b, a % b);
    return a;
}

int main()
{
    cout << cmmdc(18, 24);

    return 0;
}