#include <bits/stdc++.h>
using namespace std;

multiset<int> list1, list2;

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    int x, y;
    while (cin >> x >> y)
    {
        list1.insert(x);
        list2.insert(y);
    }
    
    int ans = 0;
    auto it1 = list1.begin();
    auto it2 = list2.begin();
    
    while (it1 != list1.end() && it2 != list2.end())
    {
        ans += abs(*it1 - *it2);

        it1++;
        it2++;
    }

    cout << ans;
    
    return 0;
}