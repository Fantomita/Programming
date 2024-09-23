#include <bits/stdc++.h>
using namespace std;

string makeNumber(int n) 
{
    string number = "2"; 

    for (int i = 1; i < n - 1; ++i) 
        number += '0';
    number += '1';

    return number;
}

int main() 
{
    int n;
    cin >> n;
    cout << makeNumber(n);
    return 0;
}