#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream cin("ccmax.in");
ofstream cout("ccmax.out");

int n, x, y, v[101], lmax, nrmax;
vector<int> a[101];
queue<int> q;

void bfs(int k)
{
    int nrc = 0;
    q.push(k);

    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        if (v[nod]) continue;
        nrc++;
        v[nod] = 1;

        for (auto el: a[nod])    
            q.push(el);
    }

    if (nrc > lmax)
    {
        lmax = nrc;
        nrmax = 1;
    }
    else if (nrc == lmax)
        nrmax++;
}

int main()
{
    cin >> n;
    while (cin >> x >> y)
    {
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
        sort(a[i].begin(), a[i].end());

    for (int i = 1; i <= n; ++i)
        if(!v[i])
        {
            bfs(i);
        }

    cout << lmax << ' ' << nrmax;
}