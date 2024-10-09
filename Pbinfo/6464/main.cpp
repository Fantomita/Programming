#include <iostream>

using namespace std;

int main()
{
    int n,i,m,a[101][101],j=1;
    cin>>n>>m;
    for(i=1;i>=n;i++)

    {
        if(i==1 && j==1)
            a[i][j]=1;
        if(i%2==1)
            for(j=2;j<=m;j++)
            a[i][j]=a[i][j-1]+1;
        else
        {
            a[i][m]=a[i-1][m];
            for(j=m;j>=1;j--)
                a[i][j]=a[i][j+1]+1;
        }
    }
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=m;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
