#include <iostream>

using namespace std;

int SumDivImp(int a[], int st, int dr)
{
    if (st > dr) return 0;

    int mij = (st + dr) / 2;
    int sum_st = SumDivImp(a, st, mij - 1);
    int sum_dr = SumDivImp(a, mij + 1, dr);

    return sum_st + sum_dr + a[mij];
}

int main()
{
    int n, a[1001];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << SumDivImp(a, 1, n);
}
