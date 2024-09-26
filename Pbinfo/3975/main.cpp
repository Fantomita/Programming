//#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("intervale.in");
ofstream cout("intervale.out");

struct pct
{

    int st, dr;
}x[200001];

bool compare(pct a, pct b)
{
    return (a.st < b.st);
}

int main()
{
    int s, d, nr = 1, n, maxv = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i].st >> x[i].dr;

    sort(x + 1, x + n + 1, compare);

    for (int i = 2; i <= n; ++i)
    {
        if (x[i].dr >= x[i - 1].st && x[i].st <= x[i - 1].dr)
            nr++;
        else
        {
            if (nr > maxv)
                maxv = nr;
            nr = 1;
        }
    }
    if (nr > maxv)
        maxv = nr;
    cout << maxv;

    return 0;
}
