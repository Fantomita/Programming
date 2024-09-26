#include <iostream>
#include <algorithm>
using namespace std;
 
int st[15],viz[15],n,m,t,a[15],nrcif,p=1,k;
 
void back(int k)
{
    if(k==m+1)
    {
        for(int i=1;i<=m;i++)
            cout<<a[st[i]];
        cout<<'\n';
    }
    else
        for(int i=1;i<=nrcif;i++)
            if(viz[i]==0)
            {
                st[k]=i;
                viz[i]=1;
                if(a[st[k]]!=0 && (k==1 || k>1 && a[st[k-1]]<a[st[k]]))
                    back(k+1);
                viz[i]=0;
            }
}
 
int main()
{
    cin>>n>>m;
    t=n;
    while(t)
    {
       nrcif++;
       a[nrcif]=t%10;
       t=t/10;
    }
    sort(a+1,a+nrcif+1,greater<int>());
    back(1);
    return 0;
}