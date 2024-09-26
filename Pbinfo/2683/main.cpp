#include <iostream>
#define NMAX 100005

using namespace std;

int n, d[NMAX], k, x, st, dr;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;

        int st = 1, dr = k;
        while(st <= dr)
        {
            int mid = (st + dr) / 2;

            if (d[mid] < x) dr = mid - 1;
            else st = mid + 1;
        }
        if (st > k) d[++k] = x;
        else d[st] = x;
    }

    cout << k;

    return 0;
}
