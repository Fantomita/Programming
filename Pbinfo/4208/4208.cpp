#include <iostream>

using namespace std;

int ExistaImpareRec(int n)
{
    if (n)
    {
        if (n % 2)
            return 1;
        else
            return ExistaImpareRec(n / 10);
    }
    else
        return 0;
}

int main()
{
    cout << ExistaImpareRec(1);

    return 0;
}