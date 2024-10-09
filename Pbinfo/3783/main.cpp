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

void StergeAfterQ(nod*&prim,nod*&ultim, nod*q)
{
    nod *r, *t;
    for (r = prim; r != q && r; r = r->urm);
    if (r->urm)
    {
        if (r == prim)
        {
            t = r->urm;
            r->urm = t->urm;
            t->urm->ant = r->urm;
            delete t;
        }
        else
        {
            t = r->urm;
            if (t->urm)
            {
                t->urm->ant = r;
                r->urm = t->urm;
                delete t;
            }
            else
            {
                r->urm = NULL;
                delete t;
            }
        }
    }
}

int main()
{
    creare_lista(p, u);
    afisare_lista(p, u);
    q = new nod;
    cin >> q->info;
    StergeAfterQ(p, u, q);
    afisare_lista(p, u);
    return 0;
}
