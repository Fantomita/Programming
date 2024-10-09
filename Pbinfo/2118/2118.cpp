#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("minlex.in");
ofstream cout("minlex.out");

char s[100005], t[200010];
int n, minv;

int main()
{
    cin >> s;
    n = strlen(s);
    strcpy(t, s);
    strcat(t, s);

    for (int i = 1; i < n; ++i)
        if(strncmp(s, t+i, n) > 0)
        {
            strncpy(s, t + i, n);
            minv = i;
        }
    
    cout << minv;
}