#include <iostream>

using namespace std;

int main()
{
       int n, a[50];
        cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for(int i = n+1 ; i > 1 ; --i)
    {
        for(int j = i ; j < i + n ; ++j)
            cout << a[j] << ' ';
        cout << endl;
    }

    return 0;
}
