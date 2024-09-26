#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *urm;
}*p, *q;
int n, x;

void creare_lista(nod *&p)
{
    nod *u;

    cout << "Numar elem lista: "; cin >> n;
    if (p == NULL)
    {
        if (n)
        {
            p = new nod;
            cout << "Elem 1: "; cin >> p->info;
            p->urm = NULL;
            u = p;
        }
        for (int i = 1; i < n; ++i)
        {
            nod *q = new nod;
            cout << "Elem " << i + 1 << ": "; cin >> q->info;
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
            cout << "Elem de adaugat : "; cin >> q->info;
            u->urm = q;
            u = q;
        }
    }
    u->urm = NULL;

}

void afisare_lista(nod *p)
{
    nod *q;
    if(p == NULL)
        cout << "Lista vida";
    for (q = p; q != NULL; q = q->urm)
        cout << q->info << ' ';
    cout << '\n';
}

void inserare(nod * & p, nod * q, int x)
{
    nod *t;
    if (p == q)
    {
        nod *r = new nod;
        r->info = x;
        r->urm = p;
        p = r;
    }
    else
    {
        for (t = p; t->urm && t->urm != q; t = t->urm);   ///poz t = poz q;
        if (t->urm)
        {
            nod *r = new nod;
            r->info = x;
            if (t->urm == NULL)
            {
                t->urm = r;
                r->urm = NULL;
            }
            else
            {
                r->urm = t->urm;
                t->urm = r;
            }
        }
    }
}

int main()
{
    creare_lista(p);
    q = new nod;
    cin >> q->info >> x;
    inserare(q, p, x);
    afisare_lista(p);
    return 0;
}
