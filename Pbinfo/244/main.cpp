#include <fstream>
using namespace std;

ifstream cin("cifreord.in");
ofstream cout("cifreord.out");

int main()
{
    int ap[10] = {}, n, x, nr = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        ap[x]++;
    }
    for (int i = 0; i <= 9; ++i)
        while (ap[i])
        {
            nr++;
            if(nr % 20)
                cout << i << " ";
            else
                cout << i << '\n';
            ap[i]--;
        }
    return 0;
}
