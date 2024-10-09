#include <iostream>
#include<algorithm>

using namespace std;

int n, st[19], v[19], k, minv=2000, a[19];

void back (int k)
{
    if (k == n + 1)
    {
        int s = 0;
        for (int i = 1; i < n;i += 2)
            s = s + a[st[i + 1]] % a[st[i]];
        if (s < minv)
            minv = s;
    }
    else
        for (int i = 1; i <= n; i++)
            if (v[i] == 0)
                {
                    st[k] = i;
                    v[i] = 1;
                    int s = 0;
                    for (int i = 1; i <= k; i += 2)
                        s = s + a[st[i + 1]] % a[st[i]];
                    if (s < minv)
                        back (k + 1);
                    v[i] = 0;
                }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    back (1);
    cout << minv;
    return 0;
}