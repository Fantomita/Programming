#include <iostream>

using namespace std;

struct island
{
    struct
    {
        int x, y, z;
    }p1, p2, p3;

    double dist;
};

island isl[105];
int n, k, question;

double calculate_dist(island x)
{
    double d;

    d = ((x.p1.x * 1.0 - x.p2.x) * (x.p1.y - x.p3.y)) / (x.p1.y - x.p2.y);

    return d;
}

void read()
{
    cin >> question;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> isl[i].p1.x >> isl[i].p1.y >> isl[i].p2.x >> isl[i].p2.y >> isl[i].p3.x >> isl[i].p3.y;
        cout << isl[i].p1.x << ' ' << isl[i].p1.y << ' ' << isl[i].p2.x << ' ' << isl[i].p2.y << ' ' << isl[i].p3.x << ' ' << isl[i].p3.y << '\n';

        isl[i].dist = calculate_dist(isl[i]);
    }
}

void solve1()
{

}

int main()
{
    read();

    for (int i = 1; i <= n; ++i)
        cout << isl[i].dist << ' ';
    return 0;
}
