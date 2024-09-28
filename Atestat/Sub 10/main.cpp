#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void printOddColumn(int c, int n, int a[][21])
{
    for (int i = 1; i <= n; ++i)
        if (a[i][c] % 2)
            fout << a[i][c] << ' ';
}

int main()
{
    int n, m, a[21][21] = {};

    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            fin >> a[i][j];        
            
            cout << a[i][j] << ' ';

            if (!a[i][j])
                a[i][0]++;
        }

        cout << '\n';
    }
    
    int k;
    bool printed = 0;
    fin >> k;

    for (int i = 1; i <= n; ++i)
        if (a[i][0] == k)
        {
            cout << i << ' ';
            printed = 1;
        }
    if (!printed)
        cout << "Nu exista";
    cout << '\n';

    int c;
    printed = 0;
    cout << "c = ";
    cin >> c;
    printOddColumn(c, n, a);

    return 0;
}