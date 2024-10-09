#include <fstream>
#include <algorithm>
 
using namespace std;

ifstream cin("submultimi1.in");
ofstream cout("submultimi1.out");
 
int st[11], viz[11], n, k;

int valid(int k)
{
    if (k > 1 && st[k] - st[k - 1] <= 1)
        return 0;
    return 1;
}

void back(int k)
{
    if (k > 1)
    {
        for (int i = 1; i < k; ++i)
            cout << st[i] << ' ';
        cout << '\n';
    }
    for (int i = 1; i <= n; ++i)
        if (viz[i] == 0)
        {
            st[k] = i;
            viz[i] = 1;
            if (k <= n && valid(k))
                back(k + 1);
            viz[i] = 0;
        }
}

int main()
{
    cin >> n;
    back(1);
}
