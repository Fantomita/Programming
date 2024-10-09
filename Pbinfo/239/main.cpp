#include <fstream>
using namespace std;

ifstream cin("nrlipsa.in");
ofstream cout("nrlipsa.out");

int main()
{
    int ap[10005] = {}, a = 0, b = 0, x;
    while (cin >> x) {
        if (x >= 100 && x <= 999) {
            ap[x]++;
        }
    }

    for (int i = 999; i >= 100 && (!a || !b); --i){
        if (ap[i] == 0) {
            if (a == 0) {
                a = i;
            }
            else if (b == 0) {
                b = i;
            }
        }
    }

    if (a && b) {
        cout << a << ' ' << b;
    }
    else {
        cout << "NU";
    }

    return 0;
}
