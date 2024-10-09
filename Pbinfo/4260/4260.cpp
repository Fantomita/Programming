//a = (2,5,1,5,3,5,5,5,7,6)
//NrXDivImp(a, 1, 6, 5) = 3
// (2, 5, 1, 5, 3, 5)
// (2, 5)  (1) (5, 3, 5)
// (2) (5)     (5) (3) (5)
//  0   1   0   1   0   1

#include <iostream>

using namespace std;

int NrXDivImp(int a[], int st, int dr, int x)
{
    if (st > dr) return 0;

    int mij = (st + dr) / 2;
    int nr_st = NrXDivImp(a, st, mij - 1, x);
    int nr_dr = NrXDivImp(a, mij + 1, dr, x);
    int nr_mij = (a[mij] == x) ? 1 : 0;

    return nr_st + nr_dr + nr_mij;
}

int main()
{
    int a[] = { 0,2,0,1,0,3,0,5,5,7,6 }, st = 1, dr = 6, x = 5;
    cout << NrXDivImp(a, st, dr, x);
}
