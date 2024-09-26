#include <fstream>

using namespace std;

ifstream cin("partitiimultime.in");
ofstream cout("partitiimultime.out");

int n, st[41], k, s;

void tipar(int k)
{

    int maxv = 0;
    for (int i = 1; i < k; ++i)
        maxv = max(st[i], maxv);

    for (int i = 1; i <= maxv; ++i)
    {
        for (int j = 1; j <= n; ++j)
            if (st[j] == i)
                cout << j;
        cout << '*';
    }
    cout << '\n';
}

void back(int k)
{

    if (k == n + 1)
        tipar(k);
    else
    {
        int maxv = 0;
        for (int i = 1; i < k; ++i)
            maxv = max(st[i], maxv);

        for (int i = 1; i <= maxv + 1; ++i)
        {
            st[k] = i;
            back(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    back(1);
    return 0;
}
