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

void FInserareKX(Nod * &head, int k, int x)
{
    if (head == NULL || k <= 1)
    {
        Nod *q = new Nod;
        q->info = x;
        if (head == NULL)
        {
            head = q;
            q->leg = NULL;
        }
        else
        {
            q->leg = head;
            head = q;
        }
    }
    else
    {
        Nod *q = head;
        int i;
        for (i = 1; q->leg && i < k - 1; ++i, q = q->leg);
        if (q)
        {
            Nod *t = new Nod;
            t->info = x;

            if (q->leg == NULL)
            {
                q->leg = t;
                t->leg = NULL;
            }
            else
            {
                t->leg = q->leg;
                q->leg = t;
            }
        }
        else
        {
            Nod *t = new Nod;
            t->info = x;
            q->leg = t;
            t->leg = NULL;
        }
    }
}

int main()
{
    creare_lista(head);
    afisare_lista(head);
    FInserareKX(head, 100, 100);
    afisare_lista(head);
    return 0;
}
