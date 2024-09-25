#include <fstream>
#include <algorithm>
 
using namespace std;
 
ifstream cin("submdiv.in");
ofstream cout("submdiv.out");
 
int m,n,k,a[25],st[25],viz[25],nr,ok;
 
void back(int k)
{
    if(k==m+1)
    {
        for(int i=1;i<=m;i++)
          cout<<a[st[i]]<<" ";
        cout<<'\n';
        ok=1;
    }
    else
        for(int i=1;i<=n;i++)
            if(viz[i]==0)
            {
               st[k]=i;
               viz[i]=1;
               if(k==1 || k>1 && a[st[k-1]]<a[st[k]])
                 back(k+1);
               viz[i]=0;
            }
}
 
int main()
{
    cin>>nr>>m;
    for(int d=1;d*d<=nr;d++)
    {
      if(nr%d==0)
        a[++n]=d;
      if(nr%d==0 && d!=nr/d)
        a[++n]=nr/d;
    }
    sort(a+1,a+n+1);
    back(1);
    if(ok==0)
       cout<<"fara solutie"; 
    return 0;
}