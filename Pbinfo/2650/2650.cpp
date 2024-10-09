#include <iostream>
using namespace std;

int st[200001];

int main()
{
    int x, i, n, vf = 0, v[200001] = {};

    cin >> n;

    for (i = 1; i <= n; ++i)
        cin >> st[i];

    for (i = 1; i <= n; ++i)
    {
        cin >> x;
        if(v[x] == 1)
            cout << 0 << ' ';
        else
        {
            int nr = 0;
            for ( ; st[vf] != x; vf++)
                {
                    v[st[vf]] = 1;
                    nr++;
                }
            cout << nr << ' ';
        }      
    }

    return 0;
}
