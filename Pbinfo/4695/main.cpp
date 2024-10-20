#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int maxv = -1e9;
        for (int j = 1; j <= n; ++j)
        {
            cin >> x;

            if (i == j && x > maxv)
                maxv = x;
            
            if (i + j == n + 1 && x > maxv)
                maxv = x;
        }

        cout << maxv << '\n';
    }

}