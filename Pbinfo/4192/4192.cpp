#include <iostream>

using namespace std;

struct date
{
    char CNP[14];
    int anNastere;
};
struct angajat
{
    struct date dp;
    int venit;
} a[30];

int main()
{
    a[0].dp.anNastere = 2000;
    a[0].venit = 4000;

    return 0;
}
