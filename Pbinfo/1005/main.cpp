#include <fstream>
#include <bitset>
using namespace std;

ifstream cin("numere8.in");
ofstream cout("numere8.out");

bitset<100000>f;

int main()
{
    int x;
    while (cin >> x)
        if(x <= 9999)
            f[x] = 1;
    for (int i = 9999; i > 0; --i)
        if (!f[i])
            cout << i << " ";
    return 0;
}
