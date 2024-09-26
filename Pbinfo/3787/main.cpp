#include <iostream>

using namespace std;

struct nod{
    int info;
    nod * ant,*urm;
}*p, *u;

int n;

void creare(nod *&p, nod *&u)
{
    cin >> n;
    p = new nod;
    cin >> p->info;
    u = p;
    p->ant = p->urm = NULL;
    for (int i = 2; i <= n; ++i)
    {
        nod *q = new nod;
        cin >> q->info;
        u->urm = q;
        q->ant = u;
        u = q;
    }
    u->urm = NULL;
}

bool Palindrom(nod* prim, nod* ultim)
{
    int n = 0;
    for (nod *q = prim ; q; n++, q = q->urm);
    nod *q = prim, *r = ultim;
    for (int i = 1; i <= n/ 2; i++)
    {
        if(q->info != r->info)
            return false;
        q = q->urm;
        r = r->ant;
    }
    return true;
}

int main()
{
    creare(p, u);
    cout << Palindrom(p, u);
    return 0;
}
