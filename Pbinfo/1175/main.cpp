#include <iostream>

using namespace std;

struct nod{
    int info;
    nod * urm;
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

int suma(nod * p)
{
    int s = 0;
    nod *q;
    for (q = p; q->urm->urm; q=q->urm)
        if (q->info % 2 == 0 && q->urm->info % 2 && q->urm->urm->info % 2 == 0)
            s += q->urm->info;

    return s;
}

int main()
{
    creare_lista(p);
    cout << suma(p);
    return 0;
}
