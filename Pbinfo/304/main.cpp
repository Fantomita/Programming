#include <fstream>

using namespace std;

long long p2[60], x;
int n, k;
char a[10002];

ifstream cin("memory006.in");
ofstream cout("memory006.out");

void pre_compute()
{
    p2[1] = 2;
    for (int i = 2; i < 60; ++i)
        p2[i] = p2[i - 1] * 2;
}

int sbinary(int st, int dr)
{
    int mij;

    while (st <= dr)
    {
        mij = (st + dr) / 2;
        if (x == p2[mij])
            return mij;
        if (x < p2[mij])
            dr = mij - 1;
        else
            st = mij + 1;
    }

    return 0;
}

int main()
{
    pre_compute();

    int st = 1, dr = 0, sum = 0, nr = 0;

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        int t = sbinary(1, 59);

        if (t == 0)
        {
            st = 1;
            dr = 0;
            sum = 0;
        }
        else
        {
            ++dr;
            dr = dr % 10002;
            a[dr] = t;
            sum += t;

            if (sum == k)
                ++nr;
            else
            {
                while (sum > k)
                {
                    sum -= a[st];
                    st++;
                    st = st % 10002;
                }

                if (sum == k)
                    ++nr;
            }
        }
    }

    cout << nr;

    return 0;
}
