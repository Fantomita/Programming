#include <iostream>

using namespace std;

struct Nod
{
    int val;
    Nod *next;
}*p, *u;

int n;

void creare_lista(Nod *&p)
{
    Nod *u;

    cout << "Numar elem lista: "; cin >> n;
    if (p == NULL)
    {
        if (n)
        {
            p = new Nod;
            cout << "Elem 1: "; cin >> p->val;
            p->next = NULL;
            u = p;
        }
        for (int i = 1; i < n; ++i)
        {
            Nod *q = new Nod;
            cout << "Elem " << i + 1 << ": "; cin >> q->val;
            u->next = q;
            u = q;
        }
        u->next = NULL;
    }
    else
    {
        u = p;
        for (int i = 1; i <= n; ++i)
        {
            Nod *q = new Nod;
            cout << "Elem de adaugat : "; cin >> q->val;
            u->next = q;
            u = q;
        }
    }
    u->next = NULL;

}

void afisare_lista(Nod *p)
{
    Nod *q;
    if(p == NULL)
        cout << "Lista vida";
    for (q = p; q != NULL; q = q->next)
        cout << q->val << ' ';
    cout << '\n';
}

void FStergeDuplicate(Nod *&L)
{
    Nod *q = L, *t;
    while(q->next)
    {
        if (q->val == q->next->val)
        {
            t = q->next;
            if (t->next)
                q->next = t->next;
            else
                q->next = NULL;
            delete t;
        }
        else
            q = q->next;
    }
}

int main()
{
    creare_lista(p);
    FStergeDuplicate(p);
    afisare_lista(p);
    return 0;
}
