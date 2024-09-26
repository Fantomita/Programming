#include <iostream>

using namespace std;

struct Nod
{
    int info;
    Nod *leg;
}*head;

int n, x, y, val;

void creare_lista(Nod *&p)
{
    Nod *u;

    cout << "Numar elem lista: "; cin >> n;
    if (p == NULL)
    {
        if (n)
        {
            p = new Nod;
            cout << "Elem 1: "; cin >> p->info;
            p->leg = NULL;
            u = p;
        }
        for (int i = 1; i < n; ++i)
        {
            Nod *q = new Nod;
            cout << "Elem " << i + 1 << ": "; cin >> q->info;
            u->leg = q;
            u = q;
        }
        u->leg = NULL;
    }
    else
    {
        u = p;
        for (int i = 1; i <= n; ++i)
        {
            Nod *q = new Nod;
            cout << "Elem de adaugat : "; cin >> q->info;
            u->leg = q;
            u = q;
        }
    }
    u->leg = NULL;
}

void afisare_lista(Nod *p)
{
    Nod *q;
    if(p == NULL)
        cout << "Lista vida";
    for (q = p; q != NULL; q = q->leg)
        cout << q->info << ' ';
    cout << '\n';
}

int FLsiDublu(Nod *head)
{
    int n = 0;
    for (Nod *q = head; q; n++, q = q->leg);
    if (n % 2)
        return -1;

    int i = 1;
    Nod *q;
    for (q = head; i < n / 2; ++i, q = q->leg);
    Nod *t = q->leg, *r = q;
    for (q = head; t; t = t->leg)
    {
        if (q->info != t->info)
            return -1;
        q = q->leg;
    }
    return r->info;
}

int main()
{
    creare_lista(head);
    cout << FLsiDublu(head);
    return 0;
}
