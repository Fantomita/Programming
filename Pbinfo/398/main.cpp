#include <fstream>

using namespace std;

ifstream cin ("plopi2.in");
ofstream cout ("plopi2.out");

int main()
{
    int n, v[105], k = 0, s = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    for (int i = 2; i <= n; ++i)
    {
        if (v[i] > v[i - 1])
        {
            k++;
            s += (v[i] - v[i - 1]);
            v[i] = v[i - 1];
        }
    }

    cout << k << ' ' << s;

    return 0;
}
