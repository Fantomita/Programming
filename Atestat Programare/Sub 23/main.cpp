#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("atestat.in");
ofstream fout("atestat.out");

struct point
{
    int x, y;
};

bool bothCoordinatesEven(point a)
{
    return (!(a.x & 1) && !(a.y & 1));
}

int main()
{
    int n, cnt = 0;
    point v[11];

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i].x >> v[i].y;

        cout << '(' << v[i].x << ',' << v[i].y << ")\n";

        if (v[i].y == 0)
            cnt++;

        if (bothCoordinatesEven(v[i]))
            fout << '(' << v[i].x << ',' << v[i].y << ")\n";
    }
    cout << cnt;

    return 0;
}