#include <iostream>

using namespace std;

int main()
{
    int a[21][21],n,i,j,sump=0,sums=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
    {
        cin>>a[i][j];
        if(i==j)
            sump+=a[i][j];
        if(j==n-i+1)
            sums+=a[i][j];
    }
    if(sump>sums)
        cout<<sump-sums;
    else
        cout<<sums-sump;
    return 0;
}
