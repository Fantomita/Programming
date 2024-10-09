#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void sortare(char a[260][260], int n)
{
    int i, j;
    for (i = 1; i < n; ++i)
        for (j = i + 1; j <= n; ++j)
            if (strlen(a[i]) < strlen(a[j]) || (strlen(a[i]) == strlen(a[j]) && strcmp(a[i], a[j]) > 0))
                swap(a[i], a[j]);
}

int main()
{
    char s[260], a[260][260], *p;
    int n = 0;

    cin.get(s, 260);

    for (p = strtok(s, " "); p; p = strtok(NULL, " "))
        strcpy(a[++n], p);

    sortare(a, n);

    for (int i = 1; i <= n; ++i)
        cout << a[i] << '\n';

    return 0;
}