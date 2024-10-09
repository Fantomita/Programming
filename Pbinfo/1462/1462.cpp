#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

#define NMAX 100001
#define MOD 666013

using namespace std;

ifstream cin("gasti.in");
ofstream cout("gasti.out");

int n, m, x, y, v[NMAX], max1 = -1, max2 = -1, members[NMAX], freq[NMAX];
vector<int> a[NMAX];

int cnt = 0;
void dfs(int nod, int g)
{
    cnt++;
    v[nod] = g;
    for (auto el : a[nod])
        if(!v[el])
            dfs(el, g);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
        sort(a[i].begin(), a[i].end());

    int nrg = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (!v[i])
        {
            cnt = 0;
            dfs(i, ++nrg);
            members[nrg] = cnt;
            freq[members[nrg]]++;

            if(members[nrg] > max1)
            {
                max2 = max1;
                max1 = members[nrg];
            }
            else if (members[nrg] > max2)
                max2 = members[nrg];
        }
    }

    long long val1, val2;
    if (max1 != max2)
    {
        x = (1LL * freq[max1] * max1) % MOD;
        y = (1LL * freq[max2] * max2) % MOD;
    }
    else
    {
        x = (1LL * max1 * max1) % MOD;
        y = (1ll * freq[max1] * (freq[max1] - 1) / 2) % MOD;
    }

    long long ans = (x * y) % MOD;

    cout << nrg << ' ' << ans;

    return 0;
}