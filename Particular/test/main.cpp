#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("bac.txt");

int main()
{
    int x, lungime = 0, produs = 0, prodMax = 0, pozMax = 0, poz = 0, lungMax = 0;
    while(fin >> x)
    {
        poz++;
        if (x == 0)
        {
            if (produs > prodMax)
            {
                lungMax = lungime;
                prodMax = produs;
                pozMax = poz - lungime;
            }
            produs = 0;
            lungime = 0;
        }
        else
        {
            if (produs == 0)
                produs = x;
            else
                produs *= x;
            lungime++;

            //cout << produs << ' ' << lungime << '\n';
        }
    }
    if (produs > prodMax)
    {
        lungMax = lungime;
        prodMax = produs;
        pozMax = poz - lungime;
    }

    cout << lungMax << ' ' << pozMax << '\n';
}