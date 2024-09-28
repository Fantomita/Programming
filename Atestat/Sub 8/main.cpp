#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

bool binarySearch(int n, int v[], int x)
{
    int left = 1, right = n, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (v[mid] < x)
            right = mid - 1;
        else if (v[mid] > x)
            left = mid + 1;
        else
            return 1;
    }
    
    return 0;
}

int main()
{
    int n, v[31], sum = 0;

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        if (v[i] > 0)
            sum += v[i];
    }

    for (int i = n; i >= 1; --i)
        cout << v[i] << ' ';
    cout << '\n';

    int x;
    cout << "X = ";
    cin >> x;
    cout << (binarySearch(n, v, x) ? "DA" : "NU");

    fout << sum;

    return 0;
}