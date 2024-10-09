#include <fstream>
#include <cstring>

using namespace  std;

ifstream cin("palindrom.in");
ofstream cout("palindrom.out");

int main()
{
    int n, i, j;
    char s[25];
    bool ok;

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin.get();
        cin.get(s, 25);
        ok = 1;

        for (int j = 0; j < strlen(s) / 2 && ok; ++j)
            if (s[j] != s[strlen(s)- j - 1]) ok = 0;
        
        cout << ok << '\n';
    }
}
