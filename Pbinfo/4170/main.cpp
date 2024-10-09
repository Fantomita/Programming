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

void FLsiDesc(Nod *head)
{
    Nod *q = head;
    for (; q -> leg; q = q->leg)
    {
        if ((q->info) - (q->leg->info) > 1)
        {
            Nod *t = new Nod;
            t->info = (q->info) - 1;
            t->leg = q->leg;
            q->leg = t;
        }
    }
    while (q->info != 1)
    {
        Nod *t = new Nod;
        t->info = (q->info) - 1;
        t->leg = NULL;
        q->leg = t;
        q = t;
    }
}

int main()
{
    creare_lista(head);
    FLsiDesc(head);
    afisare_lista(head);
    return 0;
}
