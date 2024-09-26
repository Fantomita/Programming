
#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("partitiinr.in");
ofstream cout("partitiinr.out");
int n, s[1000],k,v[1000],sum=0;
int valid(int k)
{
    if(k>1&&s[k-1]>=s[k])
        return 0;
    if(k>1&&abs(s[k-1]-s[k])<2)
        return 0;
    return 1;
}
void back(int k)
{
    if(sum==n)
    {
        for(int i=1;i<k;i++)
            cout<<s[i]<<" ";
        cout<<'\n';
    }
    else
    for(int i=1;i<=n;i++)
        if(v[i]==0)
    {
        s[k]=i;
        v[i]=1;sum+=i;
        if(sum<=n&&valid(k))
            back(k+1);

        v[i]=0;sum-=i;
    }
}
int main()
{
    cin>>n;
    back(1);
    return 0;
}
