#include <iostream>
#include <fstream>

using namespace std;

typedef pair<int, int> pii;

pii v[1005];

int main()
{
    ifstream cin("proiecte.in");
    ofstream cout("proiecte.out");

    int n;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i].first;
        v[i].second = i;
    }

    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (v[i].first > v[j].first)
                swap(v[i], v[j]);

    for (int i = 1; i <= n; ++i)
        cout << v[i].second << ' ';
    return 0;
}
