#include <iostream>
#include <cmath>

using namespace std;

unsigned long long b16(char s[], unsigned long long pt, unsigned long long &nr)
{
    if (strlen(s))
}


int main()
{
    int n, a, p, pt = 10;
    cin >> a >> n >> p;
    while(p > 1)
    {
        pt *= 10;
        p--;
    }
    cout << putere(a, n, pt);
}