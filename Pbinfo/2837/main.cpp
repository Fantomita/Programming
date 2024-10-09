#include <fstream>
#include <bitset>
using namespace std;

ifstream cin("intervale5.in");
ofstream cout("intervale5.out");

bitset<105> f;

int main()
{
    int x, maxv = -1, cnt = 0;
    while (cin >> x)
    {
        f[x] = 1;
        if (x > maxv)
            maxv = x;
    }

    for (int i = 0; i <= maxv - 2; ++i)
        if (f[i])
            for (int j = i + 2; j <= maxv; ++j)
                if(f[j])
                {
                    int ok = 1;
                    for (int k = i + 1; k < j && ok; ++k)
                        if (f[k])
                            ok = 0;
                    if (ok)
                        ++cnt, cout << i << ' ' << j << '\n';
                }

    if (!cnt)
        cout << "nu exista";

    return 0;
}
