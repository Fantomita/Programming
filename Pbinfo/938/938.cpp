#include <iostream>

using namespace std;

int suma(int v[], int n)
{
    if (n == 0)
        return 0;
    return v[n - 1] + suma(v, n - 1);
}

int main()
{
    int v[] = {12};
    cout << suma(v, 6);

    return 0;
}