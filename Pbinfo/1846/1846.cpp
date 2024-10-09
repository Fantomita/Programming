#include <iostream>
#include <climits>

using namespace std;

void ordonare(int a[], int n, int st, int dr)
{
    if (st < dr)
    {
        for (int i = st; i < dr; ++i)
            if (a[dr] < a[i])
                swap(a[i], a[dr]);
        ordonare(a, n, st, dr - 1);
    }
}

int main()
{
    int a[1005], n, st, dr;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cin >> st >> dr;
    ordonare(a, n, st, dr);
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
}