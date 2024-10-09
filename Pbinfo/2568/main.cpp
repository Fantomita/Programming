#include <fstream>
#include <bitset>
#include <algorithm>
#define MMAX 4194304
using namespace std;

ifstream cin ("cubprim.in");
ofstream cout ("cubprim.out");

bitset<MMAX> prime, r;
int n, m;

struct cub
{
    int val, poz;
}v[200001];

void eratostene()
{
    prime[0] = 1;
    for (int i = 2; i < MMAX; i++)
        if (!prime[i])
            for (int j = 2 * i; j < MMAX; j += i)
                prime[j] = 1;
}

int caut_binar(unsigned long long x)
{
    unsigned long long cub;
    int st = 1, dr = MMAX, mij = 0;
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        cub = mij;
        cub *= mij;
        cub *= mij;
        //cout << "mij = " << mij << '\n';
        if (!prime[mij] && cub == x)
            return mij;
        else if (cub < x)
            st = mij + 1;
        else
            dr = mij - 1;
    }
    return -1;
}

bool compar(cub a, cub b)
{
    return (a.val > b.val);
}

void citire()
{
    unsigned long long x;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        int t = caut_binar(x);
        //cout << t << ' ';
        if (t != -1)
        {
            ++m;
            v[m].val = t;
            v[m].poz = i;
        }
    }

    cout << m << '\n';

    sort(v + 1, v + m + 1, compar);

    for (int i = 1; i <= m; ++i)
    {
        x = 1;
        for (int j = 1; j <= 3; ++j)
            x *= v[i].val;
        cout << v[i].poz << ' ' << v[i].val << ' ' << x << '\n';
    }
}

int main()
{
    eratostene();
    citire();
    return 0;
}
