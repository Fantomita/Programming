#include <iostream>
using namespace std;
//ifstream cin("hercule.in");
//ofstream cout("hercule.out");

int n,m,a[11][11],nr,b[11][11];

void tipar()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
           cout<<a[i][j]<< " ";
        cout<<'\n';
    }
    cout<<endl;
}
void back(int i , int j , int k)
{
   if(i==n && j==m)
        {
            nr++;
            b[i][j]--;
            a[i][j]=k;
            //tipar();
        }
    if(i>=1 && i<=n && j>=1 && j<= m)
      {
       a[i][j]=k;
       b[i][j]--;
       if(i>1 && b[i-1][j]>a[i][j] && a[i-1][j]==0) back(i-1,j,k+1);
       if(i<n && b[i+1][j]>a[i][j] && a[i+1][j]==0) back(i+1,j,k+1);
       if(j>1 && b[i][j-1]>a[i][j] && a[i][j-1]==0) back(i,j-1,k+1);
       if(j<m && b[i][j+1]>a[i][j] && a[i][j+1]==0) back(i,j+1,k+1);
       b[i][j]++;
       a[i][j]=0;
      }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
          cin>>b[i][j];
    back(1,1,1);
    cout<<nr;
    return 0;
}
