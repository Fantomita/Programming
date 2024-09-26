#include <fstream>

using namespace std;

ifstream cin("circularlistinsert.in");
ofstream cout("circularlistinsert.out");

struct nod
{
    int info;
    nod *urm;
}*p, *u;

int n;

void creare(nod *&p)
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        if (p == NULL)
        {
            p = new nod;
            cin >> p->info;
            p->urm = NULL;
            u = p;
        }
        else
        {
            nod *q = new nod;
            cin >> q->info;
            u->urm = q;
            u = q;
        }
    }
    u->urm = p;
}


void afis()
{
    nod *q;
    for (q = p; q->urm != p; q = q->urm)
        cout << q->info << ' ';
    cout << q->info;
}

void rezolv()
{
    nod *q = p;
    int m, x, j;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> x;

        j = 1;
        while(j <= x)
        {
            q = q->urm;
            j++;
        }

        nod *t = new nod;
        t->info = 2 * q->info;
        t->urm = q->urm;
        q->urm = t;
        q = q->urm;
    }
}


int main()
{
    creare(p);
    rezolv();
    afis();
    return 0;
}
