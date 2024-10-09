#include <iostream>

using namespace std;

int FiboRec(int x, int y)
{
    if (x > y)
        return 0;
    if (x == 1 && y == 1)
        return 1;
    return FiboRec(y - x, x);
}

int main()
{
    cout << FiboRec(3, 5);

    return 0;
}