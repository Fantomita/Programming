#include <iostream>
using namespace std;

int verif(int n, int a[], int m, int b[])
{
    int s = 0, i = 1;
    for (int j = 1; j <= m; ++j)
    {
        while(s < b[j] && i <= n)
            s = s + a[i++];
     if (s != b[j])
        return 0;
    s = 0;
    }
    return i > n;
}

int main()
{
    int n, t, a[1005], b[1005], m;
    cin >> t;
    for (int j = 1; j <= t; ++j)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; ++i)
            cin >> b[i];
        if (verif(n, a, m, b))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}
