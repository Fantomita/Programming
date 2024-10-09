#include <iostream>

using namespace std;

int AlternDivImp(int a[], int st, int dr)
{
    if (st >= dr)
        return 1;
    if (a[st] % 2 == a[st + 1] % 2 || a[dr] % 2 == a[dr -1] % 2)
        return 0;

    return AlternDivImp(a, st + 1, dr - 1);
}

int main()
{
    int a[101]; // 1 2 3 4 5 6 7 8 9 10
    for (int i = 1; i <= 10; ++i)
        cin >> a[i];
    cout << AlternDivImp(a, 1, 8);

    return 0;
}
