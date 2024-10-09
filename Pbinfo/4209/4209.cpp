#include <iostream>

using namespace std;

int DifParImpar(int n)
{
    if (n <= 9)
    {
        if (n % 2 == 0)
            return 1;
        else
            return -1;
    }
    else
    {
        if (n % 2 == 0)
            return 1 + DifParImpar(n / 10);
        else
            return -1 + DifParImpar(n / 10);   
    }
}

int main()
{
    cout << DifParImpar(0);

    return 0;
}