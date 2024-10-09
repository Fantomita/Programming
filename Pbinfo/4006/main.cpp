#include <iostream>

using namespace std;

int main()
{
    int n, a, b, cnt = 0;
    cin >> n >> a >> b;

    while (n % a != 0)
        n -= b, cnt++;

    while(n)
    {
        cout << a << ' ';
        n -= a;
    }

    while(cnt)
    {
        cout << b << ' ';
        cnt--;
    }

    return 0;
}
