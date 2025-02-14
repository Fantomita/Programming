#include <bits/stdc++.h>
using namespace std;

int n = 1000001, ver[1000004], oriz[1000004];

void update(int poz, int val, int arb[])
{
    for(; poz <= n; poz += poz & (-poz))
    {
        arb[poz] += val;
    }
}

int query(int poz, int arb[])
{
    int s = 0;
    for (; poz > 0; poz -= poz & (-poz))
        s += arb[poz];
    return s;
}

int main()
{
    ifstream cin("dulciuri.in");
    ofstream cout("dulciuri.out");

    int Q, x, y, a, b;
    cin >> Q;
    while(Q--)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            cin >> x >> y;
            y++;
            update(x, y, ver);
        }
        else if (q == 2)
        {
            cin >> x >> y;
            x++;
            update(x, y, oriz);
        }
        else
        {
            cin >> x >> y >> a >> b;

            if (x > a)
                swap(x, a);
            if (y > b)
                swap(y, b);

            if (x == a)
                a++;
            if (y == b)
                b++;

            double xContribution = query(a, ver) - query(x, ver); // vertical updates over the x-range
            double yContribution = query(b, oriz) - query(y, oriz); // horizontal updates over the y-range
            cout << fixed << setprecision(10) << xContribution / (a - x) + yContribution / (b - y) << '\n';

}
    }

    return 0;
}