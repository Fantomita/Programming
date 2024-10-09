#include <iostream>

using namespace std;

int multiplu(int a[], int n, int k)
{
    if (n == 1)
        if ((k == 0 && a[0] % 10 == 0) || (k != 0 && a[n - 1] % k == 0 && a[n - 1] % 10 == k))
            return 1;
        else
            return 0;
    else
        if ((k == 0 && a[0] % 10 == 0) || (k != 0 && a[n - 1] % k == 0 && a[n - 1] % 10 == k))
            return 1 + multiplu(a, n - 1, k);
        else
            return multiplu(a, n - 1, k);
}

int main()
{
    int a[] = {9, 273, 63, 83, 93, 123};
    cout << multiplu(a, 6, 3);
}