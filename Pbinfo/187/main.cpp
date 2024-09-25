#include <fstream>
using namespace std;

ifstream cin("ciffrecv.in");
ofstream cout("ciffrecv.out");

int main()
{
    int x, i, ap[10] = {}, maxv = 0;;
    while (cin >> x)
        ap[x]++;
    for (i = 7; i >= 2; --i)
        if (i == 7 || i == 5 || i == 3 || i == 2)
            if (ap[i])
            {
                maxv = ap[i];
                x = i;
                break;
            }
    cout << x << " " << maxv;
    return 0;
}
