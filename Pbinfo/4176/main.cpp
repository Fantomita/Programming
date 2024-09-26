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
        }

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

void FLdiAdDupa(nod *&prim, nod *&ultim, int x)
{
    nod *q;
    int minv = prim->info;
    for (q = prim->urm; q; q = q->urm)
        if (q->info < minv)
            minv = q->info;

    for (q = prim; q && q->info != minv; q = q->urm);

    nod *t = new nod;
    t->info = x;
    if(ultim->info == minv)
    {
        t->ant = ultim;
        ultim->urm = t;
        t->urm = NULL;
    }
    else
    {
        q = q->urm;
        t->urm = q;
        q->ant->urm = t;
    }
}

int main()
{
    creare_lista(p, u);
    afisare_lista(p, u);
    cin >> x;
    FLdiAdDupa(p, u, x);
    afisare_lista(p, u);
    return 0;
}
