#include <iostream>

using namespace std;

void nr_cif_zero(int n, int& nr)
{
    if (n <= 9)
        if (n == 0)
            nr = 1;
        else 
            nr = 0;
    else
    {
        nr_cif_zero(n / 10, nr);
        if (n % 10 == 0)
            nr++;
    }
}

int main()
{
    int nr;
    nr_cif_zero(0, nr);
    cout << nr;

    return 0;
}