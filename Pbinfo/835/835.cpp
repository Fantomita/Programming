#include <iostream>

using namespace std;

void afisvec(int v[], int n)
{
    if (n == 0)
        return;

    afisvec(v, n - 1);
    cout << v[n - 1] << ' '; 
}

int main()
{
    int v[] = {3, 6, 5, 4, 2};
    afisvec(v, 5);
}