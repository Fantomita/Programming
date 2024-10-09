#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[260], t[260] = {}, *p;

    cin.get(s, 260);
    for (p = strtok(s, " "); p; p = strtok(NULL, " "))
        if (p)
        {
            strcat(t, p);
            strcat(t, " ");
        }
    t[strlen(t)] = '\0';
    
    cout << t;

    return 0;
}