#include <iostream>
using namespace std;

int main()
{
    int n, a[101][101], i, j;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (i < j)
            {
                int aux = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = aux;
            }

            cout << a[i][j] << ' ';
        }
        cout <<endl;
    }


    return 0;
}
