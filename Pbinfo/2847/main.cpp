#include <iostream>

using namespace std;

struct nod
{
    int a, b;
    nod *b;
}*p, *u;

int n;

void creare_lista(nod *&p)
{
    nod *u;

    cout << "Numar elem lista: "; cin >> n;
    if (p == NULL)
    {
        if (n)
        {
            p = new nod;
            cout << "Elem 1: "; cin >> p->a;
            p->urm = NULL;
            u = p;
        }
        for (int i = 1; i < n; ++i)
        {
            nod *q = new nod;
            cout << "Elem " << i + 1 << ": "; cin >> q->a;
            u->b = q;
            u = q;
        }
        u->b = NULL;
    }
    else
    {
        u = p;
        for (int i = 1; i <= n; ++i)
        {
            nod *q = new nod;
            cout << "Elem de adaugat : "; cin >> q->a;
            u->b = q;
            u = q;
        }
    }
    u->b = NULL;

}

void afisare_lista(nod *p)
{
    nod *q;
    if(p == NULL)
        cout << "Lista vida";
    for (q = p; q != NULL; q = q->b)
        cout << q->a << ' ';
    cout << '\n';
}

void solve(nod *&p)
{
    nod *q = new nod;
    if (p->a % 2)
        if (p->b % 2 == 0)
        {
            q->a = 2 * (p->a + p->b) - p->a;
            q->b = 2 * (p->a + p->b);
        }
        else
        {
            q->b = (p->a + p->b) / 2;
            q->a = (p->a + p->b) / 2 = p->b;
        }
    else
        if (p->b % 2 == 0)
        {
            q->a = (p->a + p->b) / 2;
            q->b = (p->a + p->b) / 2 + p->b;
        }

    for (nod *r = p; r->urm; r=r->urm)

}

int main()
{
    creare_lista(p);
    FStergeDuplicate(p);
    afisare_lista(p);
    return 0;
}
