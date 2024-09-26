#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream in("parcela.in");
ofstream out("parcela.out");

const int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
int a[105][105], n, m;
queue<pair<int, int>> q;

bool inmat(int i, int j)
{
	if (i < 0 || i > n || j < 0 || j > m)
		return false;
	return true;
}

void lee(int i, int j, int cnt, int nrp, int &amax, int &nr)
{
	q.push(make_pair(i, j));
	a[i][j] = cnt++;
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		for (int k = 0; k < 4; ++k)
		{
			int xx = x + di[k], yy = y + dj[k];
			if (a[xx][yy] == 1 && inmat(xx, yy))
			{
				q.push(make_pair(xx, yy));
				a[xx][yy] = cnt++;
				if (cnt - 2 > amax)
					amax = cnt - 2, nr = nrp;
			}	
		}
		q.pop();
	}
}

int main()
{
	int nr = 0, nrp = 0, amax = 0;

	in >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			in >> a[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == 1)
				lee(i, j, 2, ++nrp, amax, nr);
;
	out << nrp << ' ' << amax << ' ' << nr;
}
