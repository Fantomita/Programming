#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("arh.in");
ofstream fout("arh.out");

string s, t;
int ops, p;

string termen();
string dublare();
string palPar();
string palImp();

string termen()
{
    string ans;
    if (isdigit(s[p]))
        ans = dublare();
    else if (s[p] == '[' && s[p + 1] == '*')
        ans = palPar();
    else if (s[p] == '[')
        ans = palImp();
    else if (isalpha(s[p]))
        ans = s[p++];
    
    return ans;
}

string dublare()
{
    ops++;
    int n = 0;
    while(p < s.size() && isdigit(s[p]))
        n = n * 10 + (s[p++] - '0');

    string ans, temp;

    p++; // (

    while(s[p] != ')')
        temp += termen();

    while(n--)
        ans += temp;
    
    p++; // )

    return ans;
}

string palPar()
{
    ops++;
    string ans;
    p += 2; // [*

    while (s[p] != ']')
        ans += termen();
    
    for (int i = ans.size() - 1; i >= 0; --i)
        ans += ans[i];

    p++;   // ]
    
    return ans;
}

string palImp()
{
    ops++;
    string ans;
    p++; // [

    while (s[p] != '*')
        ans += termen();
    
    for (int i = ans.size() - 2; i >= 0; --i)
        ans += ans[i];

    p += 2;   // *]
    
    return ans;
}

string eval()
{
    string ans;

    while(p < s.size())
        ans += termen();

    return ans;
}

int main()
{
    fin >> s;

    string ans = eval();

    fout << ops << '\n' << ans;

    return 0;
}