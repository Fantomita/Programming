#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char c[260], *p, temp[15] = "";
    int n;
    bool ok = 0;
    cin.get(c, 260);
    cin >> n;

    for (p = strtok(c, " "); p; p = strtok(NULL, " "))
    {
        if (strlen(p) == n)
            cout << p << '\n', ok = 1;
    }

    if (!ok)
        cout << "nu exista";

    return 0;
}