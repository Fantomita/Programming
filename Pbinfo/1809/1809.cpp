#include <iostream>
#include <cstring>

using namespace std;

int putere(int a, int b)
{
    if (b == 0)
        return 1;
    else
        return putere(a, b - 1) * a;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << putere(a, b);
}