#include <bits/stdc++.h>
using namespace std;

ifstream fin("spatrat.in");
ofstream fout("spatrat.out");

int n, k;
int P[320];
int dp[100001], T[100001];

int main()
{
    fin >> n;

    int p = 1;
    while (p * p <= 100000)
    {
        P[++k] = p * p;
        p++;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k && i - P[j] >= 0; ++j)
        {
            if (dp[i] == 0)
            {
                dp[i] = dp[i - P[j]] + 1;
                T[i] = j;
            }

            else if (dp[i] > dp[i - P[j]] + 1)
            {
                dp[i] = dp[i - P[j]] + 1;
                T[i] = j;
            }
        }
    }

    fout << dp[n] << '\n';

    while (T[n])
    {
        fout << T[n] << ' ';
        n -= (T[n] * T[n]);
    }

    return 0;
}