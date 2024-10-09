#include <iostream>
using namespace std;

int cautare(int x[], int n, int y)
{
    int st = 1, dr = n, mij;
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        if (y < x[mij])
            dr = mij - 1;
        else if (y > x[mij])
            st = mij + 1;
        else return mij;
    }
    return 0;
}

void citire(int& n, int x[])
{
    int m, y;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> y;
        if (cautare(x, n, y))
            cout << "1 ";
        else cout << "0 ";
    }
}

int main()
{
    int n, x[25005], m, y;
    citire(n, x);
    return 0;
}
