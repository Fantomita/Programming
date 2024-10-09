#include <fstream>
#include <vector>

using namespace std;

ifstream cin("pachete.in");
ofstream cout("pachete.out");

int n, a[100005], k, poz[100005];
vector<pair<int, int> > op;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        poz[a[i]] = i;
    }

    poz[0] = n + 1;

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == i)
            continue;

        if (poz[0] != i)
        {
            op.push_back({i, poz[0]});

            a[poz[0]] = a[i];
            poz[a[i]] = poz[0];
            a[i] = 0;
            poz[0] = i;
        }

        op.push_back({poz[i], i});

        a[i] = i;
        a[poz[i]] = 0;
        poz[0] = poz[i];
        poz[i] = i;
    }

    cout << op.size() << '\n';
    for (auto el : op)
        cout << el.first << ' ' << el.second << '\n';

    return 0;
}
