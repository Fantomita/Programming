#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, q[4005], x, st = 1, dr = 0;
    char op[10];

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> op;

        if (strcmp(op, "push") == 0)
        {
            cin >> x;
            q[++dr] = x;
        }
        else if (strcmp(op, "pop") == 0 && st <= dr)
            st++;
        else if (strcmp(op, "front") == 0 && st <= dr)
            cout << q[st] << '\n';
    }
}