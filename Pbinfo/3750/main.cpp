#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *ant, *urm;
}*p, *u, *q;

int n, k, x;

void creare_lista(nod*& p, nod *&u)
{
    cout << "Numar elem lista:"; cin >> n;
    if (p == NULL)
    {
        if (n)
        {
            p = new nod;
            cout << "Elem 1: "; cin >> p->info;
            p->urm = NULL;
            p -> ant = NULL;
            u = p;

        for (int i = 1; i < n; i++)
        {
            nod* q = new nod;
            cout << "Elem: " << i + 1 << ": "; cin >> q->info;
            u->urm = q;
            q -> ant = u;
            u = q;
        }
        u->urm = NULL;
        }
    }
    else
    {
        u = p;
        for (int i = 1; i < n; i++)
        {
            nod* q = new nod;
            cout << "Elem de adaugat: ";
            cin >> q->info;
            u->urm = q;
            q -> ant = u;
            u = q;
        }
        u->urm = NULL;
    }
}

void afisare_lista(nod* p, nod *u)
{
    nod* q;
    if (p == NULL)
        cout << "Lista vida";
    else
        for (q = p; q; q = q->urm)
            cout << q->info << " ";
    cout << endl;
}

void InserareInainteQ(nod *& prim,nod *& ultim, nod * q,int x)
{
    nod *r;

    for (r = prim; r != q && r; r = r->urm);

    if (r)
    {
        nod *t = new nod;
        t->info = x;

        if (r == prim)
        {
            t->urm = prim;
            prim->ant = t;
            prim = t;
            t->ant = NULL;
        }
        else
        {
            t->urm = r;
            t->ant = r->ant;
            r->ant->urm = t;
        }
    }
}

int main()
{
    creare_lista(p, u);
    afisare_lista(p, u);
    q = new nod;
    cin >> q->info >> x;
    InserareInainteQ(p, u, q, x);
    afisare_lista(p, u);
    return 0;
}
