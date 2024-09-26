#include <iostream>
#include <algorithm>

using namespace std;

int n, a[15], viz[15], st[15], nr;

void back(int k)
{
    if (k == nr + 1)
    {
        for (int i = 1; i <= nr; ++i)
            cout << a[st[i]];
        cout << '\n';
    }
    else
        for (int i = 1; i <= nr; ++i)
            if (!viz[i])
            {
                st[k] = i;
                viz[i] = 1;
                if (k != 1 || (k == 1 && a[st[k]] != 0))
                    back(k + 1);
                viz[i] = 0;
            }
}

int main()
{
    cin >> n;
    do
    {
        a[++nr] = n % 10;
        n /= 10;
    }while(n);

    sort(a + 1, a + nr + 1);

    back(1);
    return 0;
}
