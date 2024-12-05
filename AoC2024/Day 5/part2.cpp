#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> rules;
vector<vector<int>> updates;

vector<string> split(const string& str, char delimiter)
{
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        tokens.push_back(token);
    return tokens;
}

bool isValidUpdate(vector<int> &update)
{
    set<int> seen;
    for (auto page : update)
    {
        seen.insert(page);
        for (int next : rules[page])
            if (seen.find(next) != seen.end())
                return false;
    }
    return true;
}

bool compare(int a, int b)
{
    if (rules[a].count(b)) return true;
    if (rules[b].count(a)) return false;

    return false;
}

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    string line;
    while (getline(cin, line) && !line.empty())
    {
        auto parts = split(line, '|');
        int first = stoi(parts[0]);
        int second = stoi(parts[1]);

        rules[first].insert(second);
        if (rules.find(second) == rules.end())
            rules[second] = set<int>();
    }

    while(getline(cin, line))
    {
        auto pageStrings = split(line, ',');
        vector<int> update;
        for (auto pageStr : pageStrings)
            update.push_back(stoi(pageStr));
        updates.push_back(update);
    }

    int ans = 0;
    for (auto update : updates)
    {
        if (isValidUpdate(update))
            continue;
        
        sort(update.begin(), update.end(), compare);

        int middleIndex = update.size() / 2;
        ans += update[middleIndex];
    }

    cout << ans << '\n';

    return 0;
}