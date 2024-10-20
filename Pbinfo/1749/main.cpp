#include <iostream>

using namespace std;

int main()
{
    int n, z, x, s = 0;
    cin >> n >> z;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> x;
            if (z == 1 && (j > i && i + j < n + 1))
                s += x;
            else if (z == 3 && (j < i && i + j > n + 1))
                s += x;
            else if (z == 2 && (j > i && i + j > n + 1))
                s += x;
            else if (z == 4 && (j < i && i + j < n + 1))
                s += x;
        }
    }

    cout << s;

    return 0;
}