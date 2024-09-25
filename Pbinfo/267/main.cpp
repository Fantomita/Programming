#include <fstream>
//#include <iostream>
using namespace std;

ifstream cin("unice.in");
ofstream cout("unice.out");

int main()
{
    int x, ap[100] = {}, n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x, ap[x]++;
    for (int i = 0; i <= 99; ++i)
        if (ap[i] == 1)
            cout << i << " ";
    return 0;
}
