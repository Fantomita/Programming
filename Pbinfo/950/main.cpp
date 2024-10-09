#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("cerc3.in");
ofstream cout("cerc3.out");

struct cerc
{
    int a, b;
}v[305];

int n, o, r;

bool compare(cerc x, cerc y)
{
    return x.b < y.a;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> o >> r;
        v[i].a = o - r;
        v[i].b = o + r;
    }

    sort(v + 1, v + n + 1, compare);

    int curr_el, nr = 1;
    curr_el = v[1].b;

    for (int i = 1; i < n; ++i)
    {
        if (curr_el < v[i + 1].a)
        {
            nr++;
            curr_el = v[i + 1].b;
        }
    }

    cout << nr;

    return 0;
}
