#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *ant, *urm;
}*p, *u;

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

void AdaugareInceput(nod * & prim , nod * & ultim, int x)
{
    if (prim == NULL)
    {
        prim = new nod;
        prim->info = x;
        ultim = prim;
        prim->urm = NULL;
    }
    else
    {
        nod *t = new nod;
        t->info = x;
        prim->ant = t;
        t->urm = prim;
        prim = t;
        prim->ant = NULL;
    }
}

int main()
{
    creare_lista(p, u);
    afisare_lista(p, u);
    cin >> x;
    AdaugareInceput(p, u, x);
    afisare_lista(p, u);
    return 0;
}
