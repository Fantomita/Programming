#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> x, pair<int, int> y)
{
    return (x.second < y.second || (x.second == y.second && x.first < y.first));
}

int main()
{
    ifstream cin("spectacole.in");
    ofstream cout("spectacole.out");

    int n;
    pair<int, int> s[105];

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i].first >> s[i].second;

    sort(s + 1, s + n + 1, compare);

    int curr_end = s[1].second, cnt = 1;

    for (int i = 2; i <= n; ++i)
        if (s[i].first >= curr_end)
        {
            cnt++;
            curr_end = s[i].second;
        }

    cout << cnt;

    return 0;
}
