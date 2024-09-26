#include <iostream>
#include <cstring>

using namespace std;

int Nr_of_ops(char s[])
{
    int cnt = 0, nrOp = 0, len = strlen(s);

    if (len % 2)
        return -1;

    for (int i = 0; i < len; ++i)
    {
        if (s[i] == '(') cnt++;
        else cnt--;

        if (cnt < 0)
        {
            nrOp++;
            cnt = 1;
        }
    }

    nrOp += cnt / 2;

    return nrOp;
}

int main()
{
    char s[1005];

    cin.get(s, 1005);

    cout << Nr_of_ops(s);
    return 0;
}
