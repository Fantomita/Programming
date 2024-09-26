#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("evenoddxxl.in");
ofstream cout("evenoddxxl.out");

int main()
{
    char s[1005];

    cin.get(s, 1005);
    cout << (((s[strlen(s) - 1] - '0') % 2) ? "Impar" : "Par");

    return 0;
}