#include <bits/stdc++.h>
using namespace std;

#define int long long

int evaluateExpression(const vector<int>& numbers, const vector<char>& operators) 
{
    int result = numbers[0];
    for (int i = 1; i < numbers.size(); ++i) 
    {
        if (operators[i - 1] == '+') 
        {
            result += numbers[i];
        } 
        else if (operators[i - 1] == '*') 
        {
            result *= numbers[i];
        }
        else if (operators[i - 1] == '|')
        {
            string concatenated = to_string(result) + to_string(numbers[i]);
            result = stoll(concatenated);
        }
    }
    return result;
}

void backtrack(int idx, const vector<int>& numbers, vector<char>& operators, int target, vector<int>& result) 
{
    int n = numbers.size();
    
    if (idx == n - 1) 
    {
        int currentResult = evaluateExpression(numbers, operators);
        if (currentResult == target) 
        {
            result.push_back(currentResult);
        }
        return;
    }

    for (char op : {'+', '*', '|'}) 
    {
        operators[idx] = op;
        backtrack(idx + 1, numbers, operators, target, result);
    }
}

bool isPossible(int target, const vector<int>& numbers) 
{
    int n = numbers.size();
    vector<char> operators(n - 1);
    vector<int> result;

    backtrack(0, numbers, operators, target, result);

    return !result.empty();
}

signed main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    string line;
    int total_result = 0;
    while (getline(cin, line))
    {
        stringstream ss(line);
        int target;
        char useless;
        ss >> target >> useless;

        vector<int> numbers;
        int temp;
        while (ss >> temp)
            numbers.push_back(temp);

        if (isPossible(target, numbers))
            total_result += target;
    }

    cout << total_result;

    return 0;
}
