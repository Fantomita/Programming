#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("lungimerandmax.in");
ofstream cout("lungimerandmax.out");

char s[10005];

int main()
{
    int i = 0, n;
    cin >> n;
    cin.get();
    cin.get(s, 10005);
    do
    {
        int j = i + n, nr = 0;
        char t[1005] = {};
        nr = n;
        while (isalpha(s[j]))
        {
            j--;
            nr--;
        }
        strncpy(t, s + i, n);
        t[nr] = '\0';
        cout << t << '\n';
        i = i + nr + 1;
    } while (i < strlen(s));

    return 0;
}