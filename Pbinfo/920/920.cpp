#include <iostream>

using namespace std;

void cifmaxmin(int n, int& max, int& min)
{
    if (n <= 9)
    {
        max = n;
        min  = n;
        return;
    }
    else
    {
        cifmaxmin(n / 10, max, min);
        if (n % 10 > max)
            max = n % 10;
        if (n % 10 < min)
            min = n % 10;
    }
}

int main()
{
    int max, min;
    cifmaxmin(54634, max, min);
    cout << max << ' ' << min;
}