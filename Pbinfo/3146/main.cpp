#include <fstream>
#include <algorithm>
#include <bitset>
using namespace std;

ifstream cin("sort4.in");
ofstream cout("sort4.out");

struct nr
{
    int val, cif, sum, prod = 1;
}v[1000005];

void arg(nr &x)
{
    int f[10] = {}, cpy = x.val;

    do
    {
        int c = cpy % 10;

        x.sum += c;
        x.prod *= c;
        f[c]++;

        cpy /= 10;
    }while(cpy);

    for (int i = 0; i < 10; ++i)
        if (f[i])
            x.cif++;
}

bool compar(nr x, nr y)
{
    return  (x.cif > y.cif) ||
            (x.cif == y.cif && x.sum < y.sum) ||
            (x.cif == y.cif && x.sum == y.sum && x.prod < y.prod) ||
            (x.cif == y.cif && x.sum == y.sum && x.prod == y.prod && x.val < y.val);
}

int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i].val;
        arg(v[i]);
    }

    sort(v + 1, v + n + 1, compar);

    for (int i = 1; i <= n; ++i)
        cout << v[i].val << ' ';

    return 0;
}
