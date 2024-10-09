#include <bits/stdc++.h>

using namespace std;

unsigned long long n, m, q;
unsigned long long a[100005];
unsigned long long daddy[100005];
unsigned long long position[100005];
vector<vector<unsigned long long>>sumpart(100005);
unsigned long long cnt;
unsigned long long cntcomp = 0;

void dfs(unsigned long long node, unsigned long long prev)
{
    //cout << node << ' ';
    if(position[node])
        return;
    
    position[node] = cnt;
    daddy[node] = cntcomp;
    sumpart[cntcomp].push_back((prev == 0 ? 0 : sumpart[cntcomp][cnt - 1]) + node);
    cnt++;
    dfs(a[node], node);
}



unsigned long long suminterval(unsigned long long start, unsigned long long amount, vector<unsigned long long> &v)
{
    
    unsigned long long sum = 0;
    unsigned long long n = v.size() - 1;
    if(start == 0) start = n;
    if(start + amount > n)
    {
        sum += (v[n] - v[start - 1]);
        
        amount = amount - (n - start + 1);
        start = 1;
    }
    
    
        sum += (v[amount + start] - v[start - 1]);
        //cout << sum << "AICI BA BOULE\n";


    
        
    return sum;
}

unsigned long long calculateSumPartinterval(unsigned long long start, unsigned long long end, unsigned long long comp)
{
    unsigned long long sum = 0;

    unsigned long long dad = daddy[comp]; 
    unsigned long long pos = position[comp];
    unsigned long long cycleLen = sumpart[dad].size() - 1;
    
    

    //nu avem destul pentru a completa primul ciclu
    

    //avem destule pentru a completa primul ciclu

        //avem destule 
    unsigned long long len = end - start + 1;

    //cout << start % cycleLen << ' ' << len % cycleLen - 1<< "\n";
    if(len % cycleLen != 0) 
        sum += suminterval(start % cycleLen, len % cycleLen - 1, sumpart[dad]);
    //cout << sum << "x\n";
    sum += sumpart[dad][cycleLen] * (len / cycleLen);
    
    return sum;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("investitie.in", "r", stdin);
    freopen("investitie.out", "w", stdout);

    cin >> n >> m;

    for(unsigned long long i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    cin >> q;

    for(unsigned long long i = 1; i <= n; ++i)
    {
        if(!position[a[i]])
        {
            cntcomp++;
            sumpart[cntcomp].push_back(0);
            cnt = 1;
            dfs(a[i],0);
        }
    }

    for(unsigned long long i = 1; i <= q; ++i)
    {
        unsigned long long z1, z2, c1, c2;
        cin >> z1 >> z2 >> c1 >> c2;
        unsigned long long sum = 0;
        for(unsigned long long x = c1; x <= c2; ++x)
        {
            unsigned long long val;
            val = calculateSumPartinterval(z1 + position[x], z2 + position[x], x);

            //cout << "VAL " << val << '\n';
            sum = sum + val;

        }
        cout << sum << '\n';
    }
    

    return 0;
}