#include <iostream>

using namespace std;

struct Nod
{
    int info;
    Nod *leg;
}*head;

int n;

void creare_lista(Nod *&head)
{
    Nod *u;

    cout << "Numar elem lista: "; cin >> n;
    if (head == NULL)
    {
        if (n)
        {
            head = new Nod;
            cout << "Elem 1: "; cin >> head->info;
            head->leg = NULL;
            u = head;
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
        u = head;
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

void afisare_lista(Nod *head)
{
    Nod *q;
    if(head == NULL)
        cout << "Lista vida";
    for (q = head; q != NULL; q = q->leg)
        cout << q->info << ' ';
    cout << '\n';
}

void FLsiElimina(Nod * &head)
{
    int pozs = 0, pozd = 0, i = 1;
    Nod *q, *r;
    for (q = head; q; ++i, q = q->leg)
        if (q->info % 3 == 0)
        {
            if (pozs == 0) pozs = i;
            pozd = i;
        }
    i = 1;
    if (head->info % 3 == 0)
    {
        while(head && i <= pozd)
        {
            r = head;
            head = head->leg;
            delete r;
            i++;
        }
    }
    else
    {
        for (q = head; i < pozs - 1; i++, q = q->leg);
        while(i < pozd)
        {
            r = q->leg;
            if (r->leg)
                q->leg = r->leg;
            else
                q->leg = NULL;
            delete r;
            i++;
        }
    }
}

int main()
{
    creare_lista(head);
    FLsiElimina(head);
    afisare_lista(head);
    return 0;
}
