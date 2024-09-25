#include <iostream>

using namespace std;

int main()
{
    int n,i,j, a[101][101]={};
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        if(i<j&&j<n-i+1)
        {
          a[i][j]=1;
          a[j][i]=3;
        }
        if(i<j&&j>n-i+1)
        {
            a[i][j]=3;
            a[j][i]=2;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
