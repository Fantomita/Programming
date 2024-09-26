#include <fstream>

using namespace std;

ifstream cin("intervale4.in");
ofstream cout("intervale4.out");

int st[100001][2];

int main()
{
    int n,x,y,vf=0,i;
    cin>>n;     
    for(i=1;i<=n;i++)     
    {         
        cin>>x>>y;             
        vf++;             
        st[vf][0]=x;             
        st[vf][1]=y;             
        while(vf>1 && st[vf][0]<=st[vf-1][1] && st[vf-1][0]<=st[vf][1])             
        {                 
            if(st[vf-1][0]<=st[vf][0])                     
                x=st[vf-1][0];                 
            else                     
                x=st[vf][0];                 
            if(st[vf][1]<=st[vf-1][1])                     
                y=st[vf-1][1];                 
            else                     
                y=st[vf][1];                 
            vf--;                 
            st[vf][0]=x;                 
            st[vf][1]=y;             
            }             
        while(vf>1 && st[vf-1][1]>=st[vf][0] && st[vf][1]>=st[vf-1][0])             
        {                 
            if(st[vf][0]<=st[vf-1][0])                     
                x=st[vf][0];                 
            else                     
                x=st[vf-1][0];                 
            if(st[vf-1][1]>=st[vf][1])                     
                y=st[vf-1][1];                 
            else                     
                y=st[vf][1];                 
            vf--;                 
            st[vf][0]=x;                 
            st[vf][1]=y;             
        }     
    }     
    // for(int i=1;i<=vf;i++)      
    //   cout<<st[i][0]<<" "<<st[i][1]<<endl;     
    cout<<vf;     
    return 0; 
}  
