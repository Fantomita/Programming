#include <bits/stdc++.h>
using namespace std;

int numberOfDigits(long long num)
{
    return (num == 0) ? 1 : static_cast<int>(log10(num) + 1);
}

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    long long x;
    vector<long long> digitStates(20, 0);

    while (cin >> x)
        digitStates[numberOfDigits(x)]++;

    int blinks = 25;

    while (blinks--)
    {
        vector<long long> nextStates(20, 0);

        for (int d = 1; d < 20; d++)
        {
            if (digitStates[d] == 0)
                continue;

            if (d % 2 == 0)
            {
                nextStates[d / 2] += 2 * digitStates[d];
            }
            else
            {
                nextStates[numberOfDigits(2024)] += digitStates[d];
            }
        }
        digitStates = nextStates;
    }

    long long totalStones = accumulate(digitStates.begin(), digitStates.end(), 0LL);
    cout << totalStones;

    return 0;
}
