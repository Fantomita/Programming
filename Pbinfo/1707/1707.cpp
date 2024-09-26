#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

ifstream cin("retea.in");
ofstream cout("retea.out");

int n, m, x, y, v[101], k;
vector<int> a[101];

void dfs(int nod, int start)
{
    ++k;
    v[nod] = 1;
    for (auto el : a[nod])
        if (!v[el] && el != start)
            dfs(el, start);
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

    //for (int i = 1; i <= n; ++i)
        //sort(a[i].begin(), a[i].end());

    for (int i = 1; i <= n; ++i)
    {
        k = 0;
        memset(v, 0, sizeof(v));

        if(i == 1)
            dfs(2, 1);
        else
            dfs(1, i);

        if (k == n - 1)
                cout << "0 ";
            else
                cout << "1 ";
    }

    return 0;
}