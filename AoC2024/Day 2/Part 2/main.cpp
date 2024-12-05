#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<int> &levels) 
{
    int n = levels.size();
    if (n < 2) return true;

    int asc = (levels[1] > levels[0]) ? 1 : (levels[1] < levels[0]) ? -1 : 0;
    if (asc == 0) return false;

    for (int i = 1; i < n; ++i) 
    {
        int diff = levels[i] - levels[i - 1];
        if (asc == 1 && diff <= 0) return false;
        if (asc == -1 && diff >= 0) return false;
        if (abs(diff) < 1 || abs(diff) > 3) return false;
    }

    return true;
}

int main() 
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    string s;
    int ans = 0;

    while (getline(cin, s)) 
    {
        stringstream sf(s);
        vector<int> levels;
        int x;
        while (sf >> x) levels.push_back(x);

        if (is_safe(levels)) 
        {
            ans++;
            continue;
        }

        bool dampened_safe = false;
        for (int i = 0; i < levels.size(); ++i) 
        {
            vector<int> temp = levels;
            temp.erase(temp.begin() + i);
            if (is_safe(temp)) 
            {
                dampened_safe = true;
                break;
            }
        }

        if (dampened_safe) ans++;
    }

    cout << ans << endl;

    return 0;
}
