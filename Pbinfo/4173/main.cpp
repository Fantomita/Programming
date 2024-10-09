#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *ant, *urm;
}*p, *u;

int FLdiCauta(nod *prim, nod *ultim, int k)
{
    int n = 0;
    for (nod *q = prim; q; n++, q = q->urm);
    if (k > n)
        return ultim->info;
    else if(-k > n)
        return prim->info;
    else
    {
        if (k < 0)
            k = -k;
        nod *q;
        int i = 0;
        for (q = prim; q && i < k - 1; i++, q = q -> urm);
        return q->info;
    }
}

int main()
{
    FLdiCauta(p, u, 4);
    return 0;
}
