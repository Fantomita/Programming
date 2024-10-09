#include <iostream>
#include <climits>

using namespace std;

void ordonare(int a[], int n)
{
    if (n > 1)
    {
        for (int i = 0; i < n - 1; ++i)
            if (a[n - 1] < a[i])
                swap(a[i], a[n - 1]);
        ordonare(a, n - 1);
    }
}

int main()
{
    int a[1005], n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ordonare(a, n);
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
}