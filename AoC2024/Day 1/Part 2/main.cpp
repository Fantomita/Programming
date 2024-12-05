#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> list2;
multiset<int> list1;

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    int x, y;
    while (cin >> x >> y)
    {
        list1.insert(x);
        list2[y]++;
    }

    int ans = 0;
    for (auto it : list1)
    {
        ans += it * list2[it];
    }

    cout << ans;

    return 0;
}