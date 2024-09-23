#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   freopen("urat.in","r",stdin);
   freopen("urat.out","w",stdout);
    
    
    int n;
    cin >> n;
   
        ll ans = (n-1);
        if(n % 2 == 0){
            ll start = 2;
            while(start < n){
                ans += start*2;
                start+=2;
            }
        }
        else {
            ans++;
            ll start = 3;
            while(start < n){
                ans += start*2;
                start+=2;
            }
        }
    
    cout<<ans;
    
    
    
    

    return 0;
}