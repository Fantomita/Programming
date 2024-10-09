#include <iostream>

using namespace std;

struct fractie
{
    int a, b;
} f, fs;

int main()
{
    fs.a = 2020 * f.b - 2021 * f.a;
    fs.b = 2021 * f.b;

    return 0;
}
