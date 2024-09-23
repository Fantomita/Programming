#include <bits/stdc++.h>

using namespace std;

struct building
{
    long long l, h, e;
} up[100005], down[100005];

int n, m;


void read()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        long long l, h, e;
        cin >> l >> h >> e;

        up[i] = {l, h, e};
    }

    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        long long l, h, e;
        cin >> l >> h >> e;

        down[i] = {l, h, e};
    }
}

void solve()
{
    int i = 0, j = 0;
    long long bestUp = 0, bestDown = 0;
    while (i <= n || j <= m)
    {
        long long mini = min(up[i].l, down[j].l);

        up[i].l -= mini;
        down[j].l -= mini;
        
        bestUp += mini, bestDown += mini;

        long long moveUp = 0, moveDown = 0;
        
        if (up[i].l == 0) moveUp = abs(up[i + 1].h - up[i].h);
        if (down[j].l == 0) moveDown = abs(down[j + 1].h - down[j].h);

        long long lift = up[i].e + down[j].e;

        long long cpy = bestUp;
        bestUp = min(bestUp + moveUp, bestDown + lift + moveUp);
        bestDown = min(bestDown + moveDown, cpy + lift + moveDown);
        
        if (up[i].l == 0) i++;
        if (down[j].l == 0) j++;


       //cout << bestUp << ' ' << bestDown << '\n';
    }

    cout << min(bestUp, bestDown) << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("superhedgy.in", "r", stdin);
    freopen("superhedgy.out", "w", stdout);

    read();
    solve();

    return 0;
}