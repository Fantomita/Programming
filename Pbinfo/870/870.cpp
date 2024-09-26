#include <iostream>

using namespace std;

struct stiva
{
    char A, B, C;
    int v, poz;
}e[1001];

int main()
{
    int a[1001] = {}, b[1001] = {}, c[1001] = {}, vfb = 0, vfc = 0, x, k = 1, n, i, ok = 1;

    cin >> n;

    for (i = 1; i <= n; ++i)
        cin >> a[i];

    for (i = n; i >= 1 && ok; --i)
    {
        if (a[i] == k && e[k].v == 0)
        {
            c[++vfc] = a[i];
            k++;
            e[k].poz = i;
            e[k].v = 1;
            e[k].A = 'A';
            e[k].C = 'C';
            e[k].B = ' ';
        }
        else
        {
            while(b[vfb] == k + 1)
            {
                e[b[vfb]].poz = i;
                e[b[vfb]].v = 1;
                e[b[vfb]].B = 'B';
                e[b[vfb]].C = 'C';
                e[b[vfb]].A = ' ';
                c[++vfc] = b[vfb--];
                k++;
            }
            if (a[i] > k && e[a[i]].v == 0 && (a[i] < b[vfb] || vfb == 0))
            {
                b[++vfb] = a[i];
                e[a[i]].poz = i;
                e[a[i]].v = 1;
                e[a[i]].A = 'A';
                e[a[i]].B = 'B';
                e[a[i]].C = ' ';
            }
            else
                ok = 0;
        }
    }

    while(b[vfb] == k)
    {
        e[b[vfb]].poz = ++i;
        e[b[vfb]].v = 1;
        e[b[vfb]].B = 'B';
        e[b[vfb]].C = 'C';
        e[b[vfb]].A = ' ';
        c[++vfc] = b[vfb--];
        k++;
    }

    if (ok)
    {
        for (i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (e[j].poz == i)
                {
            
                if (e[i].A == 'A')
                    cout << "A ";
                if (e[i].B == 'B')
                    cout << "B ";
                if (e[i].C == 'C')
                    cout << "C ";
                cout << '\n';
                }
    }
    else
        cout << 0;

}