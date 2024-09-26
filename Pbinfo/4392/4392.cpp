#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("arhitect.in");
ofstream fout("arhitect.out");

int n, xi, yi, xf, yf, maxap, nrp;
unordered_map<long double, int> tgs;
vector<pair<long long, long long>> v;

long long cmmdc(int a, int b)
{
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}

void read()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> xi >> yi >> xf >> yf;

        xf -= xi;
        yf -= yi;

        if (yf < 0)
            xf = -xf, yf = -yf;

        if (xf < 0)
        {
            int aux = xf;
            xf = yf;
            yf = -aux;
        }

        long long cmdc = cmmdc(xf, yf);
        xf /= cmdc;
        yf /= cmdc;

        v.push_back({xf, yf});
        /*
        int c1 = abs(xf - xi), c2 = abs(yf - yi), dc = cmmdc(c1, c2);
        c1 /= dc;
        c2 /= dc;
        if (c1 > c2)
            swap(c1, c2);

        long double tg = (long double)c1/c2 + (long double)c2/c1;
        //cout << c1 << ' ' << c2 << ' ' << tg << '\n';
        tgs[tg]++;
        maxap = max(maxap, tgs[tg]);
        */
    }
}

bool compare(pair<long long, long long> a, pair<long long, long long> b)
{
    return (a.first < b.first || (a.first == b.first && a.second < b.second));
}

int main()
{
    read();
    //fout << maxap;
    sort(v.begin(), v.end(), compare);
    long long nmax = -1, nc = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        while(v[i].first == v[i + 1].first && v[i].second == v[i + 1].second && i <= v.size())
            nc++, i++;
        nc++;
        nmax = max(nc, nmax);
        nc = 0;
    }
    fout << nmax;
    cout << maxap;
    return 0;
}