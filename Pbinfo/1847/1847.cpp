#include <iostream>

using namespace std;

int suma(int v[], int n, int i, int j)
{
    if (n == 1)
        if (i > 1)
            return v[1];
        else
            return 0;
    else
        if (n < i || n > j)
            return v[n] + suma(v, n - 1, i, j);
        else
            return suma(v, n - 1, i, j);
}

int main()
{
    int v[] = {0, 12, 7, 6, 3, 8, 5}, i = 2, j = 4;

    cout << suma(v, 6, i, j);

    return 0;
}