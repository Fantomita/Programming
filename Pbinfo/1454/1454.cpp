#include <fstream>
#include <cstring>
using namespace std;

ifstream cin("permutarecuvant.in");
ofstream cout("permutarecuvant.out");

int main()
{
    char a[25], t[25];
    int n;
    cin.get(a, 25);
    n = strlen(a);
    for (int i = 0; i < strlen(a); ++i)
    {
        cout << a << ' ';

        strcpy(t, a + 1);
        int n = strlen(t);
        t[n] = a[0];
        t[n + 1] = '\0';
        strcpy(a, t);
    }

    return 0;
}