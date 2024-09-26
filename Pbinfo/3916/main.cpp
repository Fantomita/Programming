#include <iostream>

using namespace std;

int m, st[20], viz[20], a[20], k, nr;
unsigned long long n, maxv;

void formare(int &nr, int a[], unsigned long long n)
{
    if (n)
        formare(nr, a, n / 10);
    if (n)
        a[++nr] = n % 10;
}

void back(int k)
{
    if (k == nr - m + 1)
    {
        unsigned long long aux = 0;
        for (int i = 1; i <= nr - m; ++i)
            aux = aux * 10 + a[st[i]];
        if (aux > maxv)
            maxv = aux;
    }
    else
        for (int i = 1; i <= nr; ++i)
            if (!viz[i])
            {
                st[k] = i;
                viz[i] = 1;
                if (k == 1 || k > 1 && st[k - 1] < st[k])
                    back(k + 1);
                viz[i] = 0;
            }
}

int main()
{
    cin >> n >> m;

    formare(nr, a, n);

    back(1);
    cout << maxv;



    return 0;
}
