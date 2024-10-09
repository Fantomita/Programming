#include <iostream>
using namespace std;

void citire(int &n, int a[])
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}

void interclasare1(int n, int a[], int &k, int b[])
{
    int x, i;
    i = 1;
    k = 0;
    for(int j = 1;j <= n; j++)
    {
        cin >> x;
        while(a[i] < x && i <= n)
            i++;
        if(i <= n && a[i] == x)
            if(k == 0 || k >= 1 && b[k] != x)
                b[++k] = x;
    }
}

int interclasare2(int k, int b[], int n)
{
    int x, i;
    i = 1;
    for(int j = 1; j <= n; j++)
    {
        cin >> x;
        while(i <= k && b[i] < x)
            i++;
        if(i <= k && b[i] == x)
            return x;
    }
    return -1;
}

int main()
{
    int n, a[100001], b[100001], k;
    citire(n, a);
    interclasare1(n, a, k, b);
    cout << interclasare2(k, b, n);
    return 0;
}
