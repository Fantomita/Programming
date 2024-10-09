#include <iostream>

using namespace std;

void num(int n, int v[])
{
    if (n == 1)
    {
        v[0] = 0;
        return;
    }
    else if (v[n - 1] <= v[0])
        v[n - 1] = 0;
    
    num(n - 1, v); 
}

int main()
{
    int n, v[55];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    num(n, v);
    for (int i = 0; i < n; ++i)
        cout << v[i] << ' ';
    return 0;
}