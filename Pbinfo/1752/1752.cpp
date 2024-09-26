#include <iostream>
#include <cstring>

using namespace std;

unsigned nr_aparitii(char *sir, char *secventa)
{
    if (strstr(sir, secventa))
        return 1 + nr_aparitii(strstr(sir, secventa) + strlen(secventa), secventa);
    else
        return 0;
}

int main()
{
    cout << nr_aparitii("maimuta_samurai", "mu");
}