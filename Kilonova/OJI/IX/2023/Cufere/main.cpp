#include <bits/stdc++.h>

using namespace std;

map<int, int> ID;
vector<int> IDs;
bool notPrime[105];

void generateSieve()
{
    notPrime[0] = 1;
    notPrime[1] = 1;

    for (int i = 2; i <= 100; ++i)
        for (int j = i * i; j <= 100; j += i)
            notPrime[j] = 1;
}

int main()
{
    generateSieve();

    ifstream cin("cufere.in");
    ofstream cout("cufere.out");

    int c, n;

    cin >> c >> n;
    for (int i = 1; i <= 3 * n; ++i)
        for (int j = 1; j <= 9; ++j)
        {
            int x;

            cin >> x;
            if (x)
                ID[x % 100] += x / 100;
        }

    if (c == 1)
    {
        for (pair<int, int> id : ID)
            cout << id.first << ' ' << id.second << '\n';

        return 0;
    }

    for (auto temp : ID)
        IDs.push_back(temp.first);

    int col = 1, lin = 1;
    for (int i = 0; i < IDs.size(); ++i)
    {
        if (col > 9)
        {
            col = 1;
            lin++;
            cout << '\n';
        }

        int id = IDs[i], cnt = ID[id];

        if (!notPrime[id])
        {
            if (cnt > 16)
            {
                cout << 16 << id << ' ';
                col++;

                ID[id] -= 16;

                i--;
                continue;
            }
            else
            {
                cout << cnt << id << ' ';
                col++;
            }
        }
        else
        {
            if (cnt > 64)
            {
                cout << 64 << id << ' ';
                col++;

                ID[id] -= 64;

                i--;
                continue;
            }
            else
            {
                cout << cnt << id << ' ';
                col++;
            }
        }
    }

    if (col > 9)
    {
        cout << '\n';
        lin++;
        col = 1;
    }

    while (lin <= 3 * n && col < 10)
    {
        cout << 0 << ' ';
        col++;

        if (col > 9)
        {
            cout << '\n';
            lin++;
            col = 1;
        }
    }


    return 0;
}