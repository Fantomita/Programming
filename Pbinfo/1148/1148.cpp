#include <iostream>

using namespace std;

bool ExistImpDivImp(int a[], int st, int dr)
{
    if (st > dr) return 0;

    int mij = (st + dr) / 2;
    bool imp_st = ExistImpDivImp(a, st, mij - 1);
    bool imp_dr = ExistImpDivImp(a, mij + 1, dr);
    bool imp_mij = (a[mij] % 2) ? 1 : 0;

    return (imp_st || imp_dr || imp_mij);
}

int main()
{
    int n, a[101];

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    cout << (ExistImpDivImp(a, 1, n) ? "DA" : "NU");
}
