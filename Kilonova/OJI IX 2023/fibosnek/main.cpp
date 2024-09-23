#include <bits/stdc++.h>

using namespace std;

struct seq
{
    long long sum;
    int x, y;
    int len;

    bool operator<(seq &P)
    {
        if (y != P.y)
            return y < P.y;
        else
            return x < P.x;
    }
};

int c, n, m;
vector<int> fiboNumbers;
unordered_map<int, bool> isFib;
vector<seq> sequences;
pair<long long, int> aux[1505];

void fib()
{
    fiboNumbers.push_back(1);
    fiboNumbers.push_back(1);
    isFib[1] = 1;

    for (int i = 2; i < 46; ++i)
    {
        fiboNumbers.push_back(fiboNumbers[i - 1] + fiboNumbers[i - 2]);
        isFib[fiboNumbers[i]] = 1;
    }
}

int main()
{
    ifstream cin("fibosnek.in");
    ofstream cout("fibosnek.out");

    fib();

    int cnt = 0;

    cin >> c >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int x;
            cin >> x;

            if (isFib.count(x))
            {
                cnt++;
                if (c == 1) continue;

                if (aux[j].first > 0)
                    aux[j].first += x, aux[j].second++;
                else
                {
                    if (aux[j].first != 0)
                        sequences.push_back({aux[j].first, i, j, aux[j].second});
                    aux[j].first = x;
                    aux[j].second = 1;
                }
            }
            else
            {
                if (c == 1) continue;

                auto it = lower_bound(fiboNumbers.begin(), fiboNumbers.end(), x);
                auto prevIt = prev(it, 1);

                // cout << x << ' ' << *it << '\n';
                x = abs(*prevIt - x) > abs(*it - x) ? *it : *prevIt;
                
                if (aux[j].first < 0)
                    aux[j].first -= x, aux[j].second++;
                else
                {
                    // cout << "Here is the value: " << x << ' ' << i << ' ' << j << '\n';
                    if (aux[j].first != 0)
                        sequences.push_back({aux[j].first, i, j, aux[j].second});
                    aux[j].first = -x;
                    aux[j].second = 1;
                }
            }

            if (i == n && aux[j].first != 0)
                sequences.push_back({aux[j].first, i, j, aux[j].second});
        }
    }

    if (c == 1)
    {
        cout << cnt;

        return 0;
    }

    sort(sequences.begin(), sequences.end());

    for (auto it : sequences)
         cout << it.sum << ' ' << it.y << ' ' << it.x << ' ' << it.len << '\n';
    cout << '\n';

    long long sum = 0, best = -1, sumiau = 0;
    int len = 0, leniau = 0, bestLen = 0;

    for (int i = 0; i < sequences.size(); ++i)
    {
        int elem = sequences[i].sum;
        int elemlen = sequences[i].len;
        cout << "Elem: " << elem << '\n';
        if (elem < 0)
        {
            sumiau = sum;
            leniau = len;
            cout << "Sum: " << sum << ' ' << len << '\n';
            while (elem < 0 && i < sequences.size())
            {
                sumiau -= elem;
                leniau += elemlen;
                cout << "Sumiau: " << sumiau << ' ' << leniau << '\n';
                elem = sequences[++i].sum;
                elemlen = sequences[i].len;
            }
            sum = 0;
            len = 0;
        }

        if (i >= sequences.size())
        {
            if (len > bestLen)
            {
                bestLen = len;
                best = sum;
            }
            if(leniau > bestLen)
            {
                bestLen = leniau;
                best = sumiau;
            }
            break;
        }

        sum += elem;
        len += elemlen;
        sumiau += elem;
        leniau += elemlen;

        cout << "Here: " << sum << ' ' << len << ' ' << sumiau << ' ' << leniau << '\n';

        if (len > bestLen)
        {
            bestLen = len;
            best = sum;
        }
        if (leniau > bestLen)
        {
            bestLen = leniau;
            best = sumiau;
        }
    }

    cout << best << '\n';

    return 0;
}