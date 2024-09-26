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

void LsiAdd(Nod *&head, int val, int x, int y)
{
    if(head->info == val)
    {
        Nod *q = new Nod;
        q->info = x;
        q->leg = head;
        head = q;

        q = q->leg;
        if(q->leg)
            {
                Nod *t = new Nod;
                t->info = y;
                t->leg = q->leg;
                q->leg = t;
            }
        else
        {
            Nod *t = new Nod;
            t->info = y;
            q->leg = t;
            t->leg = NULL;
        }
    }
    else
    {
        Nod *q;
        for (q = head; q -> leg && q->leg->info != val; q = q->leg);
        if(q->leg)
        {
            Nod *t = new Nod;
            t->info = x;
            t->leg = q->leg;
            q->leg = t;

            q = q->leg->leg;
            if(q->leg)
            {
                Nod *t = new Nod;
                t->info = y;
                t->leg = q->leg;
                q->leg = t;
            }
            else
            {
                Nod *t = new Nod;
                t->info = y;
                q->leg = t;
                t->leg = NULL;
            }
        }
    }
}

int main()
{
    creare_lista(head);
    afisare_lista(head);
    cin >> val >> x >> y;
    LsiAdd(head, val, x, y);
    afisare_lista(head);

    return 0;
}
