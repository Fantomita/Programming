#include <iostream>

using namespace std;

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

void inserare(nod *p)
{
    if (p)
    {
        nod *q = p;
        for (q; q != NULL; q = q->urm)
            if (q->info % 2 == 0)
            {
                nod *t = new nod;
                t->info = 2 * q->info;
                t->urm = q->urm;
                q->urm = t;
                q = q->urm;
            }
    }
}

int main()
{
    creare_lista(p);
    inserare(p);
    afisare_lista(p);
    return 0;
}
