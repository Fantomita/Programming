#include <fstream>
using namespace std;

ifstream cin("cifreord1.in");
ofstream cout("cifreord1.out");

int main()
{
    int x, ap[10] = {}, nr = 0;
    while(cin >> x) {
        do {
            ap[x % 10]++;
            x /= 10;
        } while (x);
    }

    for (int i = 9; i >= 0; --i) {
        while (ap[i]) {
            cout << i << ' ';
            ++nr;
            --ap[i];
            if(nr % 20 == 0) {
                cout << '\n';
            }
        }
    }

    return 0;
}
