#include <bits/stdc++.h>
using namespace std;

int numberOfDigits(long long num)
{
    return (num == 0) ? 1 : static_cast<int>(log10(abs(num)) + 1);
}

long long splitNumber(long long num, bool leftHalf)
{
    int digits = numberOfDigits(num);
    int halfDigits = digits / 2;

    if (leftHalf)
        return num / static_cast<long long>(pow(10, digits - halfDigits));
    else
        return num % static_cast<long long>(pow(10, halfDigits));
}

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    int blinks = 75;
    map<long long, long long> currentStates;

    long long x;
    while (cin >> x)
        currentStates[x]++;

    for (int _ = 0; _ < blinks; _++)
    {
        map<long long, long long> nextStates;

        for (auto &[num, count] : currentStates)
        {
            if (num == 0)
                nextStates[1] += count;
            else if (numberOfDigits(num) % 2 == 0)
            {
                long long leftHalf = splitNumber(num, true);
                long long rightHalf = splitNumber(num, false);
                nextStates[leftHalf] += count;
                nextStates[rightHalf] += count;
            }
            else
            {
                long long newNum = num * 2024;
                nextStates[newNum] += count;
            }
        }

        currentStates = nextStates;
    }

    long long totalStones = 0;
    for (auto &[_, count] : currentStates)
        totalStones += count;

    cout << totalStones << endl;
    return 0;
}