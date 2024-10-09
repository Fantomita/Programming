#include <fstream>

using namespace std;

ifstream cin("elimin_prime.in");
ofstream cout("elimin_prime.out");

struct nod
{
    int info;
    nod *urm;
};

nod *p;
int n, poz, v;

void creare_lista(nod *&p)
{
    nod *u;

    cin >> n;
    if (p == NULL)
    {
        if (n)
        {
            p = new nod;
            cin >> p->info;
            p->urm = NULL;
            u = p;
        }
        for (int i = 1; i < n; ++i)
        {
            nod *q = new nod;
            cin >> q->info;
            u->urm = q;
            u = q;
        }
        u->urm = NULL;
    }
    else
    {
        u = p;
        for (int i = 1; i <= n; ++i)
        {
            nod *q = new nod;
            cin >> q->info;
            u->urm = q;
            u = q;
        }
    }
    u->urm = NULL;

}

int prim(int x)
{
    if ( x <= 1 || x % 2 == 0 && x != 2)
        return false;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;
    return true;
}

void elim(nod *&p)
{
    int nr = 0;
    nod *t = p;
    int i = 1;
    while(p && prim(i) || i == 1)
    {
        cout << p->info << ' ';
        i++;
        nod *q = p;
        p = p->urm;
        delete q;
        nr++;
        t = p;;
    }
    while(t)
    {
        while(!prim(i + 1) && i + 1 <= n)
        {
            i++;
            t = t->urm;
        }
        if(i < n)
        {
            cout << t->urm->info << ' ';
            nod *q = t->urm;
            if (q->urm)
                t->urm = q->urm;
            else
                t->urm = NULL;
            delete q;
            nr++;
            i++;
        }
        else
            t = t->urm;
    }
    n = n - nr;
}

int main()
{
    creare_lista(p);
    while(p)
        elim(p);
    return 0;
}
