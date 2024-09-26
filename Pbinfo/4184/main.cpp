#include <iostream>
#include <cstring>
using namespace std;

void FNume(char s[], char id[])
{
    strcpy(id, strcat(strchr(s, ' ') + 1, "2022"));
}

int main()
{
    char s[50], id[50];
    cin.get(s, 50);
    FNume(s, id);
    cout << id;
    return 0;
}
