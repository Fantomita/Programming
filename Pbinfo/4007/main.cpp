#include <iostream>

using namespace std;

int main()
{
    int n, a, b, cnt = 0;
    cin >> n >> a >> b;

    while (n % b != 0)
        n -= a, cnt++;

    while(cnt)
    {
        cout << a << ' ';
        cnt--;
    }

    while(n)
    {
        cout << b << ' ';
        n -= b;
    }

    return 0;
}
