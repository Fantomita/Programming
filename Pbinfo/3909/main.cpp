#include <iostream>

using namespace std;

int st[14], viz[14], k, a, b;

void tipar(int k)
{
    for(int i = 1; i <= k; ++i)
        cout << st[i] + a - 1 << ' ';
    cout << '\n';
}

void back(int k)
{
    if (k == b - a + 2)
        tipar(k - 1);
    else
        for(int i = 1; i <= b - a + 1; i++)
            if(viz[i] == 0)
            {
                st[k] = i;
                viz[i] = 1;
                back(k + 1);
                viz[i] = 0;
            }
}

int main()
{
    cin >> a >> b;
    back(1);

    return 0;
}
