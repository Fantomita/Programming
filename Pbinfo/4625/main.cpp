#include<bits/stdc++.h>

using namespace std;

ifstream in("mugur.in");
ofstream out("mugur.out");

struct elem{
    int sum, sufmax;
};

int n, p;
string s;
int v[100005];
elem a[400005];

void update(int nod, int st, int dr, int poz, int val){
    if(st==dr){
        a[nod].sum=a[nod].sufmax=val;
    }else{
        int mid=(st+dr)/2;
        if(poz<=mid){
            update(2*nod, st, mid, poz, val);
        }else{
            update(2*nod+1, mid+1, dr, poz, val);
        }
        a[nod].sum=a[2*nod].sum+a[2*nod+1].sum;
        a[nod].sufmax=max(a[2*nod+1].sufmax, a[2*nod].sufmax+a[2*nod+1].sum);
    }
}

int query(int nod, int st, int dr, int target){
    //cout<<st<<" "<<dr<<" "<<target<<'\n';
    if(a[nod].sufmax<1){
        return -1;
    }
    if(st==dr){
        return st;
    }
    int mid=(st+dr)/2;
    if(a[2*nod+1].sufmax>=target){
        return query(2*nod+1, mid+1, dr, target);
    }else{
        target-=a[2*nod+1].sum;
        return query(2*nod, st, mid, target);
    }
}

int main(){
    in>>n;
    for(int i=1; i<=n; i++){
        in>>p>>s;
        if(s=="push"){
            in>>v[p];
            update(1, 1, n, p, 1);
        }else{
            update(1, 1, n, p, -1);
        }
        int q=query(1, 1, n, 1);
        if(q==-1){
            out<<-1<<'\n';
        }else{
            out<<v[q]<<'\n';
        }
    }
    return 0;
}