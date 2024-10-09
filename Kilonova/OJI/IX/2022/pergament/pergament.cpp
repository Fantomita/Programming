#include <bits/stdc++.h>

using namespace std;

struct line
{
    int x, y, val;

    bool operator< (line &P)
    {
        return x < P.x;
    }
};

vector<line> v;

int prefixSum[53];

int main()
{
    ifstream cin("pergament.in");
    ofstream cout("pergament.out");

    int n, k, q;
    int a, b, c, d;
    int x, y;

    cin >> n >> k >> q;
    cin >> a >> b >> c >> d;
    cin >> x >> y;

    for (int i = 1; i <= q; ++i)
    {
        int lin, col, len;
        cin >> col >> lin >> len;

        v.push_back({lin, col, 1});
        v.push_back({lin + len, col, -1});
    }

    sort(v.begin(), v.end());

    int curr = 0, ans = 0;

    for (int i = 1; i <= n; ++i)
    {
        while(curr < v.size() && v[curr].x <= i)
        {
            for (int j = v[curr].y; j <= k; ++j)
            {
                prefixSum[j] += v[curr].val;
            }
            curr++;
        }

        ans += prefixSum[x + y - 1] - prefixSum[x - 1];
        x = 1 + (x * a + b) % k;
        y = 1 + (y * c + d) % (k - x + 1);
    }
    
    cout << ans << '\n';

    return 0;
}