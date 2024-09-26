#include <iostream>

using namespace std;

int cautare(int n, double X[], double v)
{
    if (X[n - 1] == v)
        return n - 1;
    if (X[n - 1] > v)
        return cautare(n - 1, X, v);
    else
        return -1;
}

int main()
{
    int n;
    double X[105], v;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> X[i];
    cin >> v;
    cout << cautare(n, X, v);
    return 0;
}