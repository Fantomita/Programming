#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

double sumLine(int n, double a[][11], int k)
{
    double sum = 0;
    for (int j = 1; j <= n; ++j)
        sum += a[k][j];

    return sum;        
}

int main()
{
    int n;
    double a[11][11], sum = 0;
    
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            fin >> a[i][j];

            cout << a[i][j] << ' ';

            if (i == j)
                sum += a[i][j];
        }    
        cout << '\n'; 
    }       

    cout << sum / n << '\n';

    int k;
    cout << "k = ";
    cin >> k;
    fout << sumLine(n, a, k);

    return 0;
}