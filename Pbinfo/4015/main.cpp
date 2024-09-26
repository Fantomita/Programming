#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;

bitset<200005> ap1, ap2;
char s[200005];

int main()
{
    int x, i, nr = 0, maxv = 0;
    char c;
    cin.getline(s, 200005);
    stringstream ss(s);
    while (ss >> x)
    {
        if(!ap1[x])
            ap1[x] = 1;
        else
            ap2[x] = 1;
        if(x > maxv)
            maxv = x;
    }
    for (i = 1; i <= maxv; ++i)
        if (ap1[i] && !ap2[i])
            ++nr;
    cout << nr;

    return 0;
}
