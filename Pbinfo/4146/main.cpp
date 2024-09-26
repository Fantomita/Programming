#include <iostream>

using namespace std;

int main()
{
    int n,maxv,j,poz,x,m=0;
    cin >> n;

    int v[1001];
    for(int i = 1; i <= n; ++i)
        {
            cin >> x;
            if(x%10==0)
                v[++m]=x;
        }
        n=m;
            for(int i=1;i<=n;i++)
        {
            maxv=v[i];
            for(int j=i+1;j<=n;j++)
                if(v[j]>=maxv)
            {
                maxv=v[j];
                poz=j;
            }
            swap(v[i],v[poz]);

        }
        if(m==0)
            cout<<"NU EXISTA";
        else

        for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";


    return 0;
}
