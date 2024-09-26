#include <iostream>
using namespace std;
struct Nod
{
    int info;
    Nod *leg;
};
Nod *h1,*h2,*h;
int n;
void creare_lista(Nod *&head)
{
    Nod *u;
    cout<<"Numar elem lista:";cin>>n;
    if(head==NULL)
    {
        if(n)
        {
            head=new Nod;
            cout<<"Elem 1: ";cin>>head->info;
            head->leg=NULL;
            u=head;
        }
        for(int i=1; i<n; i++)
        {
            Nod *q=new Nod;
            cout<<"Elem: "<<i+1<<": ";cin>>q->info;
            u->leg=q;
            u=q;
        }
        u->leg=NULL;
    }
    else
    {
        u=head;
        for(int i=1; i<n; i++)
        {
            Nod *q=new Nod;
            cout<<"Elem de adaugat: ";
            cin>>q->info;
            u->leg=q;
            u=q;
        }
        u->leg=NULL;
    }
}
void afisare_lista(Nod *head)
{
    Nod *q;
    if(head==NULL)
        cout<<"Lista vida";
    else
        for(q=head; q; q=q->leg)
            cout<<q->info<<" ";
    cout<<endl;
}
void LsiInterclasare(Nod *h1, Nod *h2, Nod *&h)
{
    Nod *u = h,*q=h1,*r=h2, *t;
    if(h == NULL)
    {
        if(h1->info < h2->info)
            {
                t = h1;
            }
        else
        {
            t = h2o;
        }
        t->leg = NULL;
        u = t;
        h = u;
    }
    while(h1->leg && g2->leg)
    {
        if(q->leg->info <= r->leg->info)
        {
            t = q;
            q = q->leg;
            u->leg = t;
            u = t;
        }
        else
        {
            t->info = r->info;
            r =r->leg;
        }
        u->leg = t;
        u = t;
    }
    while(q)
    {
        t->info = q->info;
        q = q->leg;
        u->leg = t;
        u = t;
    }
    while(r)
    {
        t = r;
        r = r->leg;
        u->leg = t;
        u = t;
    }
    u->leg = NULL;
}

int main()
{
    creare_lista(h1);
    afisare_lista(h1);
    creare_lista(h2);
    afisare_lista(h2);
    LsiInterclasare(h1,h2,h);
    afisare_lista(h);
    return 0;
}
