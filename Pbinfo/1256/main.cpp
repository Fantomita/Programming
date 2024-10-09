#include <iostream>

using namespace std;

struct node {
  char key;
  node *next;
}*p;

void creare_lista(node *&p)
{
    node *u;
    int n;

    cout << "Numar elem lista: "; cin >> n;
    if (p == NULL)
    {
        if (n)
        {
            p = new node;
            cout << "Elem 1: "; cin >> p->key;
            p->next = NULL;
            u = p;
        }
        for (int i = 1; i < n; ++i)
        {
            node *q = new node;
            cout << "Elem " << i + 1 << ": "; cin >> q->key;
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
            node *q = new node;
            cout << "Elem de adaugat : "; cin >> q->key;
            u->next = q;
            u = q;
        }
    }
    u->next = NULL;

}

void afisare_lista(node *p)
{
    node *q;
    if(p == NULL)
        cout << "Lista vida";
    for (q = p; q != NULL; q = q->next)
        cout << q->key << ' ';
    cout << '\n';
}

bool palindrom(node *l)
{
    node *q, *p = NULL, *r;
    int n = 0, mij;

    for (q = l; q; n++, q = q->next);

    if (n % 2) n = n / 2 + 1;
    else n = n / 2;
    mij = n;

    for (q = l; n; q = q->next, n--);
    for(; q; q = q->next)
    {
        if (p == NULL)
        {
            p = new node;
            p->key = q->key;
            p->next = NULL;
        }
        else
        {
            r = new node;
            r->key = q->key;
            r->next = p;
            p = r;
        }
    }

    for (q = l, r = p; mij; mij--, q = q->next, r = r->next)
        if (q->key != r->key)
            return false;
    return true;
}

int main()
{
    creare_lista(p);
    cout << palindrom(p);
    return 0;
}
