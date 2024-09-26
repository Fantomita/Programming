#include <iostream>

using namespace std;

int PalRec(int a[], int st, int dr)
{
    if (st <= dr)
    {
        if (a[st] != a[dr])
            return 0;
        else
            return PalRec(a, st + 1, dr - 1);
    }
    else
        return 1;
}

int main()
{
    int a[] = {0, 3, 5, 6, 5, 3, 3, 5, -1, 5};
    cout << PalRec(a, 4, 7);

    return 0;
}