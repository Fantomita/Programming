#include <fstream>

using namespace std;

long long n, e, s, t = 1, ktot;

int main()
{
    ifstream cin("eureni.in");
    ofstream cout("eureni.out");

    cin >> s >> n >> e;

    int k = 0;
    while (t <= s && k <= n)
        t *= e, k++;
    t /= e;
    k--;

    while(s)
    {
        k = 0;
        while (s >= t)
            s -= t, ++k;

        if(k)
            cout << t << ' ' << k << '\n';

        ktot += k;
        t /= e;
    }

    cout << ktot;

    return 0;
}
