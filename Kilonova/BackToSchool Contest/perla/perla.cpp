#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

const int P = 31;
const int MOD = 1e9 + 9;

int scor_maxim(const std::string& s) 
{
    int n = s.size();
    std::vector<long long> p_pow(n);

    p_pow[0] = 1;
    for (int i = 1; i < n; ++i) 
    {
        p_pow[i] = (p_pow[i - 1] * P) % MOD;
    }

    unordered_map<long long, pair<int, int>> freq;
    int max_scor = 0;

    long long hash_value = 0;
    for (int i = 0; i < n; ++i) 
    {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow[i]) % MOD;

        freq[hash_value].second++;
        freq[hash_value].first = i + 1;

        max_scor = max(max_scor, freq[hash_value].second + freq[hash_value].first);
    }

    return max_scor;
}

int main() 
{
    string S;
    cin >> S;

    cout << scor_maxim(S) << std::endl;

    return 0;
}
