#include <fstream>

using namespace std;

ifstream cin("partitiinumar.in");
ofstream cout("partitiinumar.out");

int n, st[41], k, s;

void back(int k)
{

    if (s == n)
    {
        for (int i = 1; i < k; ++i)
            cout << st[i] << ' ';
        cout << '\n';
    }
    else
        for (int i = 1; i <= n; ++i)
        {
            st[k] = i;
            s = s + i;
            if (k <= n && s <= n && (k == 1 || k > 1 && st[k] >= st[k - 1]))
                back(k + 1);
            s = s - i;
        }
}

int main()
{
    cin >> n;
    back(1);
    return 0;
}
