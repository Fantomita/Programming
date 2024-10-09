#include <iostream>

using namespace std;
int nrcif(int n)
{
   int nr=0;
   do{
        nr++;
        n=n/10;
    }while(n);
    return nr;
}

int main()
{
    int n,a[10][10],i,j,x;
    cin>>n;
    x=nrcif(n);
    while(n)
    {
        for(int i=1;i<=x;i++)
            a[i][j]=n%10;
        n=n/10;
        j++;
    }
    for(int i=1;i<=x;i++)
    {
        for(int j=i;j<=x;j++)
            cout<a[i][j]<<" ";
            cout<<endl;
    }
    return 0;
}
