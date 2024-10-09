#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, bool> closeNumbers, closeCloseNumbers;

int countDigits(int x)
{
    int cnt = 0;
    do
    {
        cnt++;
        x /= 10;
    }while(x);

    return cnt;
}

int countCloseNumber(int x)
{
    int digits = 0, cnt0 = 0, cnt9 = 0;
    bool pos1 = 0;

    do
    {
        if (x / 10 == 0 && x % 10 == 1) pos1 = 1;
        if (x % 10 == 0) cnt0++;
        if (x % 10 == 9) cnt9++;

        digits++;
        x /= 10;
    }while(x);

    if (digits == 1 && pos1 == 1)
        return 2;

    digits = digits - cnt0 - cnt9;

    int ways = 0;

    ways = 2 * digits + cnt0 + cnt9 - pos1;

    return ways;
}

void generateAllNumbers(int x, bool &ok, unordered_map<int, bool> &numbers)
{
    vector<int> digits;

    // cout << "Digits of number " << x << " are: ";
    do
    {
        digits.push_back(x % 10);
        x /= 10;
    } while (x);

    reverse(digits.begin(), digits.end());

    // for (auto it: digits)
    //     cout << it << ' ';
    // cout << '\n';

    for (int i = 0; i < digits.size(); ++i)
    {
        int temp1 = 0, temp2 = 0;
        for (int j = 0; j < digits.size(); ++j)
        {
            if (j != i)
            {
                temp1 = temp1 * 10 + digits[j];
                temp2 = temp2 * 10 + digits[j];
            }                
            else
            {
                if (digits[j] - 1 >= 0)
                    temp1 = temp1 * 10 + digits[j] - 1;
                else
                    temp1 = -1;
                if (digits[j] + 1 <= 9)
                    temp2 = temp2 * 10 + digits[j] + 1;
                else
                    temp2 = -1;
            }
        }

        // cout << temp1 << ' ' << temp2 << '\n';
        
        if (temp1 >= 0 && countDigits(temp1) == digits.size() && numbers[temp1] == 0)
        {
            numbers[temp1] = 1;
            ok = 1;
        }
        if (temp2 >= 0 && countDigits(temp2) == digits.size() && numbers[temp2] == 0)
        {
            numbers[temp2] = 1;
            ok = 1;
        }
    }
}


int main()
{
    ifstream cin("aproape.in");
    ofstream cout("aproape.out");

    int c, n;

    cin >> c >> n;

    if (c == 1)
    {
        cout << countDigits(n);

        return 0;
    }
    if (c == 2)
    {
        cout << countCloseNumber(n);

        return 0;
    }

    bool ok = 0;
    generateAllNumbers(n, ok, closeNumbers);
    
    // for (auto it : closeNumbers)
    //     cout << it.first << ' ';
    // cout << '\n';

    while (ok)
    {
        // cout << "Entered while loop\n";
        ok = 0;

        for (auto it : closeNumbers)
        {
            // cout << "Called function with parameter: " << it.first << '\n';
            generateAllNumbers(it.first, ok, closeCloseNumbers);
        }
    };

    // for (auto it : closeCloseNumbers)
    //     if (it.second == 1)
    //         cout << it.first << ' ';
    // cout << '\n';

    cout << closeCloseNumbers.size();

    return 0;
}