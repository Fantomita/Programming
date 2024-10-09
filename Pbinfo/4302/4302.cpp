#include <fstream>

using namespace std;

ifstream cin("status.in");
ofstream cout("status.out");

int main()
{
    char s[1000005] = {}, c;
    int k = 0, n, i;
    
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> c;
        if (k > 0 && s[k - 1] == c)
            k--;
        else s[k++] = c;
    }
    s[k] = '\0';

    cout << s;

    return 0;
}