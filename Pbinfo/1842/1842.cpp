#include <iostream>

using namespace std;

void F(int n, int a[], int& k)
{
    if (n == 0)
    {
        k = -1;
        return;
    }

    F(n - 1, a, k);
    if (a[n - 1] % 2 == 0)
    {
        if (k == -1)
            k = 0;
        k = k * 10 + a[n - 1];
    }
}

int main()
{
    int a[] = {3, 3, 5, 3, 3, 1}, c;
    F(6, a, c);
    cout << c;

    return 0;
}