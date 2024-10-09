#include <fstream>

using namespace std;

ifstream cin("izolate.in");
ofstream cout("izolate.out");

int main()
{
    int n, a[101][101] = {}, x, y, cnt = 0;

    cin >> n;
    while(cin >> x >> y)
    {
        if (a[x][y] == 0)
        {
            a[x][0]++;
            a[y][0]++;
        }
        a[x][y] = a[y][x] = 1;
    }

    for (int i = 1; i <= n; ++i)
        if (a[i][0] == 0) cnt++;

    cout << cnt << ' ';

    for (int i = 1; i <= n; ++i)
        if (a[i][0] == 0)
            cout << i << ' ';

    return 0;
}
