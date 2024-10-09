#include <iostream>

using namespace std;
int k,st[7],v[7],ok,c[7],viz[7],s,n;
int back(int k)
{
    if(k==n+1)
    {
        int sum=0;
        for(int j=1;j<=k;j++)
            sum+=st[j]*v[j];
        if(sum==s)
        {
            for(int i=1;i<=n;i++)
                cout<<st[i]<<" ";
            ok=1;
        }

    }
    else
        for(int i=0;i<=c[k];i++)
    {
        st[k]=i;
        int sum=0;
        for(int j=1;j<=k;j++)
            sum+=st[j]*v[j];
        if(sum<=s && ok==0)
            back(k+1);
    }
}
int main()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    back(1);
}
