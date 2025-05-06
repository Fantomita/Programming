#include <bits/stdc++.h>
using namespace std;

vector<long long> stones;

int numberOfDigits(long long num) 
{
    return (num == 0) ? 1 : static_cast<int>(log10(num) + 1);
}

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    long long x;
    while (cin >> x)
        stones.push_back(x);

    int index = 0, blinks = 25;
    while (blinks > 0)
    {
        if (stones[index] == 0)
        {
            stones[index] = 1;
            index++;
        }
        else
        {
            int nr = numberOfDigits(stones[index]);

            if (nr % 2 == 0)
            {
                long long divisor = pow(10, nr / 2);

                long long first = stones[index] / divisor;
                long long second = stones[index] % divisor;

                stones[index] = first;
                stones.insert(stones.begin() + index + 1, second);

                index += 2;
            }
            else
            {
                stones[index] *= 2024;
                index++;
            }
        }
        
        if (index == stones.size())
        {
            index = 0;
            blinks--;
        }
    }

    cout << stones.size();

    return 0;
}