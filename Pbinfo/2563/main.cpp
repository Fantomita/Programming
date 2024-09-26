#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *urm;
};

nod *p;
int n, poz, v, x;

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

void ins_cresc(nod *&p, int x)
{
    if (p->info > x)
    {

        nod *q = new nod;
        q->info = x;
        q->urm = p;
        p = q;
    }
    else
    {
        nod *t;
        for (t = p; t->urm && t->urm->info < x; t = t->urm);
        nod *q = new nod;
        q->info = x;
        if (t->urm)
        {
            q->urm = t->urm;
            t->urm = q;
        }
        else
        {
            t->urm = q;
            q->urm = NULL;
        }
    }
}

int main()
{
    creare_lista(p);
    cin >> x;
    ins_cresc(p, x);
    afisare_lista(p);


    return 0;
}
