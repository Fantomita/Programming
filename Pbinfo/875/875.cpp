#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char op[5];
    int s[1001], k = 0, n, i;
    
    cin >> n;

    for (i = 1; i <= n; ++i)
    {
        cin.get();
        cin >> op;

        if (strcmp(op, "push") == 0)
            cin >> s[k++];
        else if (strcmp(op, "top") == 0 && k != 0)
            cout << s[k - 1] << '\n';
        else if (strcmp(op, "pop") == 0 && k > 0)
            k--;
    }

    return 0;
}
