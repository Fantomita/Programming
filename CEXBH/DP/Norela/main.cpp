#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[20];

int main()
{
    ifstream cin("norela.in");
    ofstream cout("norela.out");

    cin >> n >> m;
    for (int i = 0; i <= m; ++i)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);
        int num;

        while(ss >> num)
        {
            a[i] = a[i] ^ (1 << num);
            cout << num << ' ';
        }
    }

    return 0;
}