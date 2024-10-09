#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NMAX 70005
#define zeros(x) ((x ^ (x - 1)) & x)

using namespace std;
using VI = vector<int>;

ifstream fin("ijk.in");
ofstream fout("ijk.out");

int n;
VI aib(NMAX), a;

void Add(int x, int quantity)
{
    int i;

    for (i = x; i <= N; i += zeros(i))
        aib[i] += quantity;
}

int Compute(int x)
{
    int i, ret = 0;

    for (i = x; i > 0; i -= zeros(i))
        ret += aib[i];
    return ret;
}

void read()
{
	fin >> n;
	a = VI(n + 1);

	for (int i = 1; i <= n; ++i)
		fin >> a[i];

    sort(a.begin() + 1, a.end() + 1);
}

int main()
{
	read();

	return 0;
}