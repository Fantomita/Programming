#include <fstream>
using namespace std;

ifstream cin("maxcif.in");
ofstream cout("maxcif.out");

int main()
{
    int x, maxv = -1, ap[10] = {};
    while (cin >> x)
    {
        ap[x]++;
        if(ap[x] > maxv)
            maxv = ap[x];
    }
    for (int i = 0; i <= 9; ++i)
        if (ap[i] == maxv)
            cout << i << " ";
    return 0;
}
