#include <iostream>

using namespace std;

int main()
{
    int n,m,i,j,a[101][101],k=1;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cin>>a[i][j];
    }
    for(i=1;i<=n;i++)
       {
           for(j=1;j<=m;j++)
        if(i!=0 && j!=0)
        if(a[i+1][j]!=a[i][j+1]!=a[i-1][j]!=a[i][j-1])
        cout<<a[i][j]<<" ";
       }
    cout<<k;
    return 0;
}
