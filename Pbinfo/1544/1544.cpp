#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("muzical.in");
ofstream cout("muzical.out");

int main()
{
    int n, sum = 0, i, j;
    char c[8][4] = {"do1", "re", "mi", "fa", "sol", "la", "si", "do2"}, s[4];
    cin >> n;

    for (i = 1; i <= n; ++i)
    {
        cin >> s;
        for (j = 0; j < 8; ++j)
            if (strcmp(s, c[j]) == 0)
                sum = (sum + j) % 8;
    }

    cout << c[sum];

    return 0;
}