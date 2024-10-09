#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

void sortBetweenPos(int p1, int p2, double v[])
{
    for (int i = p1; i < p2; ++i)
        for (int j = i + 1; j <= p2; ++j)
            if (v[i] > v[j])
            {
                double temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
}

int main()
{
    int n, cntNeg = 0;
    double v[31], sumNeg = 0;

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];

        cout << v[i] << ' ';

        if (v[i] < 0)
        {
            sumNeg += v[i];
            cntNeg++;
        }
    }
    cout << '\n';    
    if (cntNeg)
        cout << setprecision(2) << fixed << sumNeg / cntNeg;
    else
        cout << 0;

    int p1, p2;
    cout << "\nP1 = ";
    cin >> p1;
    cout << "P2 = ";
    cin >> p2;

    sortBetweenPos(p1, p2, v);

    for (int i = 1; i <= n; ++i)
        fout << v[i] << ' ';

    return 0;
}