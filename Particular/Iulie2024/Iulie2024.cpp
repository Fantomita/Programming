#include <iostream>
using namespace std;

int majImp (int a, int b)
{
    for (int i = a; i <= b; ++i)
    {
        int sumImp = 0, sumPar = 0;

        for (int d = 2; d * d <= i; ++d)
        {
            if (i % d == 0)
            {
                if (d & 1)
                    sumImp += d;
                else
                    sumPar += d;

                if (i / d != d)
                {
                    if (i / d & 1)
                        sumImp += i / d;
                    else
                        sumPar += i / d;
                }
            }
        }

        if (sumImp > sumPar)
            return i;
    }

    return 0;
}

int main()
{
    cout << majImp(16, 30);
    return 0;
}