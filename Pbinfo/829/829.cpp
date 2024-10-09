#include <iostream>

using namespace std;

void afis()
{
    int x;
    cin >> x;

    if (x)
    {
        afis();
    cout << x << ' ';
    }
    else
    {
        cout << x << ' ';
        return;
    }   
        
}

int main()
{
    afis();
    return 0;
}