#include <fstream>
//#include <iostream>
using namespace std;

ifstream cin("secvk.in");
ofstream cout("secvk.out");

int main()
{
    int a[100001], n, p = 1, k, maxv = 0;
    unsigned long long s = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (s > maxv && i > k)
            p = i - k, maxv = s;
        s += a[i];
        if (i > k)
            s -= a[i - k];
        //cout << p << " " << i << " " << s << '\n';
    }
    for (int i = p; i <= p + k - 1; i++)
        cout << a[i] << " ";
    return 0;
}
