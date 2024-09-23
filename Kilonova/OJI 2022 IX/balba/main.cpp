#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int c, n, cnt1, cnt2;
vector<int> v(100005);
vector<int> freq(10);

int main()
{
    ifstream cin("balba.in");
    ofstream cout("balba.out");

    cin >> c >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        freq[v[i]]++;
        if (v[i] == v[i - 1])
            cnt1--;
        if (i > 1 && v[i] == v[i - 1] && v[i] != v[i - 2])
            cnt2++;
    }

    if (c == 1)
    {
        cout << n + cnt1 << '\n' << cnt2;
        return 0;
    }

    bool ok = 1;
    int mini = 1e9;
    for (int i = 0; i <= 9; ++i)
        if (freq[i] % 2)
            ok = 0;

    for (int i = 0; i <= 9; ++i)
        if (freq[i] >= 2)
        {
            mini = i;
            break;
        }

    

    return 0;
}