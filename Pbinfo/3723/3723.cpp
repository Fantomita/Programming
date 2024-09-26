#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve1();

void read()
{
    int p, t;
    cin >> p >> t;

    if (p == 1)
    {
        for (int i = 1; i <= t; ++i)
            solve1();
    }
}

void solve1()
{
    int n, k, maxv = -1;
    cin >> n >> k;

    vector<string> days;
    for (int i = 1; i <= n; ++i)
    {
        string s;

        cin >> s;

        days.push_back(s);
    }

    int countPackets = 0;
    vector<int>types(25, 0);
    for (int i = 0; i < days.size() + 1; ++i)
    {
        bool isComplete = true;
        for (int j = 1; j <= k && isComplete; ++j)
            if (types[j] == 0)
                isComplete = false;

        if (isComplete)
        {
            fill(types.begin(), types.end(), 0);
            countPackets++;
        }
        
        if (i < days.size())
        {
            string currentDay = days[i];
            for (int j = 0; j < currentDay.size(); ++j)
            {
                if (currentDay[j] == '1')
                    types[j + 1] = 1;
            }
        }
    }
    cout << countPackets << '\n';
}

int main()
{
    read();

    return 0;
}
