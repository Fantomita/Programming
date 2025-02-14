#include <iostream>
using namespace std;

void NrImp(int x, int y, int &nr)
{
    nr = 0;

    for (int i = x; i <= y; ++i)
    {
        int divs = 0;
        for (int d = 1; d <= i; ++d)
            if (i % d == 0 && (d & 1))
                divs++;
        if (divs == 3)
            nr++;
    }
}

int main()
{
    int x, y, nr;
    cin >> x >> y;
    NrImp(x, y, nr);
    cout << nr;

    return 0;
}