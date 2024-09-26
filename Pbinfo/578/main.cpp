#include <iostream>
#include <algorithm>
using namespace std;

void citire(int& n, int a[])
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

int main()
{
    int n, a[100005], i = 2;
    unsigned long long s = 0, nr = 1;
    citire(n, a);
    //sort(a + 1, a + n + 1);
    while(i <= n)
    {
        if (a[i] == a[i - 1])
            ++nr;
        else
            s = s + nr * (nr + 1) / 2, nr = 1;
        ++i;
    }
    s = s + nr * (nr + 1) / 2;
    cout << s;
    return 0;
}
