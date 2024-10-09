#include <iostream>

using namespace std;

int main()
{
    int x, y, n = 0, m = 0;

    while(cin >> x >> y)
    {
        if (x > n) n = x;
        if (y > n) n = y;
        m++;
    }

    cout << 2 - n + m;

    return 0;
}
