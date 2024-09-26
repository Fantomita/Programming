#include <fstream>
#include <cstring>

using namespace std;

ifstream cin("coada1.in");
ofstream cout("coada1.out");

int m, x, q[50005], st = 1, dr;
char op[10];

int findVal(int val)
{
    for (int i = st; i <= dr; ++i)
        if (q[i] == val)
            return i;
    return -1;
}

int main()
{
    cin >> m;
    
    for (int i = 1; i <= m; ++i)
    {
        cin >> op >> x;

        int poz = findVal(x);

        if (strcmp(op, "push") == 0)
        {
           
            if (poz != -1)
                st = poz + 1;
            q[++dr] = x;
        }
        else
        {
            cout << ((poz != -1) ? poz - st + 1 : poz) << '\n';
        }
    }
}