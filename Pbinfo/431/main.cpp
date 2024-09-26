#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream cin("graf_complet.in");
    ofstream cout("graf_complet.out");

    int nrg, n, x, i, j;

    cin >> nrg;
    for (int k = 1; k <= nrg; ++k)
    {
        int cnt = 0;

        cin >> n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                cin >> x;

                cnt += x;
            }
        if (cnt == n * n - n)
            cout << "DA\n";
        else
            cout << "NU\n";
    }
    return 0;
}
