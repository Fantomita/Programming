#include <fstream>

using namespace std;

ifstream cin("secvente.in");
ofstream cout("secvente.out");

int main()
{
    int n, x, y, lenc = 1, nrsecv = 0;
    cin >> n >> x;
    for (int i = 2; i <= n; ++i)
    {
        cin >> y;
        if (y >= x)
        {
            lenc++;
        }
        else
        {
            lenc = 1;
            nrsecv++;
        }
        x = y;
    }
    if (y >= x)
        nrsecv++;
        
    cout << nrsecv;
}