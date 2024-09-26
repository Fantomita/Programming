#include <iostream>
using namespace std;

struct data
{
int x,y,z,poz;

}a,minv,maxv;

int main()
{    
    int n,i;
    cin>>n>>a.x>>a.y>>a.z;
    a.poz=1;
    minv=maxv=a;
    for(i=2;i<=n;i++)
    {        
        cin>>a.x>>a.y>>a.z;
        a.poz=i;
        if(a.x==maxv.x)
            if(a.y==maxv.y)
            {
                     if(a.z<maxv.z)
                        maxv=a;
                }
                else
                {
                        if(a.y<maxv.y)
                            maxv=a;
                    }
                else
                {
                    if(a.x<maxv.x)
                        maxv=a;
                    }
                        if(a.x==minv.x)
                        if(a.y==minv.y)
                        {
                                 if(a.z>minv.z)
                                    minv=a;
                            }            else            {                if(a.y>minv.y)                    minv=a;            }        else        {        if(a.x>minv.x)            minv=a;        }

    }    cout<<minv.poz<<" "<<maxv.poz;    return 0;
}

