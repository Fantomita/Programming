#include <iostream>

using namespace std;
int n, m;
int a[105][105],st[105];
int b;
void back(int k)
{
    if (k==n+1)
    {
       /* cout<<"DA\n";
        int ok = st[1];
        for(int i = 1 ; i<=n;i++)
            if(st[i]==ok)
                cout<< i << " ";
        cout << "\n";
        for(int i = 1; i<= n; i++)
            if(st[i]!=ok)
                cout<<i<<" "; */
                for(int i=1;i<=n;i++)
                    cout<<st[i]<< " ";
                cout<<endl;
                //b=1;
    }
    else
        for(int i=1;i<=2;i++)
    {
        st[k]=i;
        int ev=1;
        for(int j = 1; j<k;j++)
            if(a[j][k]==1 && st[j]==i)
                ev=0;
            if(ev && b==0)
                back(k+1);
    }


}
int main()
{
    int x,y;
    cin>>n>>m;
    for(int i=1 ; i<=m; i++)
    {
        cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    back(1);
    if(b==0)
        cout<<"NU";
    return 0;
}
