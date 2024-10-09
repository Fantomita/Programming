#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<int> vecA(n), vecB(m);
    unordered_map<int, int> freqA, freqB;

    for (int i = 0; i < n; ++i) 
    {
        cin >> vecA[i];
        freqA[vecA[i]]++;
    }

    for (int i = 0; i < m; ++i) 
    {
        cin >> vecB[i];
        freqB[vecB[i]]++;
    }

    int commonElements = 0;
    for (auto pair: freqA) 
    {
        int value = pair.first;
        int count = pair.second;
        if (freqB.find(value) != freqB.end()) 
            commonElements += min(count, freqB[value]);
    }

    int mismatchCost = min(n, m) - commonElements;
    int sizeDifferenceCost = abs(n - m);
    int totalCost = mismatchCost + sizeDifferenceCost;

    cout << totalCost << endl;

    return 0;
}
