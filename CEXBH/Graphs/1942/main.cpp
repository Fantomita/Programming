#include <bits/stdc++.h>
using namespace std;

vector<int> ans(400);

void multiply(vector<int> &v, int number)
{
    int remainder = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        int product = v[i] * number + remainder;
        v[i] = product % 10;
        remainder = product / 10;
    }
}

int main()
{
    ans[0] = 1;

    int n;
    cin >> n;

    for (int i = 3; i < n; ++i)
        multiply(ans, i);

    bool ok = false;
    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
    {
        if (*it == 0 && !ok) continue;
        ok = true;  
        cout << *it;
    }

    return 0;
}