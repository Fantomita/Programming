#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *urm;
};

nod *p, *q;
int n, poz, v;

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

void sterge(nod * & p, nod * q)
{
    nod *r, *t;

    if (p == q)
    {
        r = p;
        p = p->urm;
        delete r;
    }
    else
    {
        for (t = p; t->urm && t->urm != q; t = t->urm);
        if (t->urm)
        {
            r = t->urm;
            if (r->urm)
                t->urm = r->urm;
            else
                t->urm = NULL;
            delete r;
        }
    }
}

int main()
{
    creare_lista(p);
    afisare_lista(p);
    q = new nod;
    cin >> q->info;
    sterge(p, q);
    afisare_lista(p);
    return 0;
}
