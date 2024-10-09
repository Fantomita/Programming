#include <iostream>
#include <fstream>
#include <map>
#include <queue>

#define NMAX 200005

using namespace std;

ifstream fin("parcare.in");
ofstream fout("parcare.out");

typedef pair<int, int> pii;

struct park
{
    int index, arrived;
};

map<int, park> p;
priority_queue<pii, vector<pii>, greater<pii>> pq;

int N, M, T, arrive, leave;

void read()
{
    fin >> N >> M >> T;
    for (int i = 1; i <= N && i <= M; ++i)
    {
        fin >> arrive >> leave;

        p[leave] = { i, arrive };

        fout << i << '\n';
    }
    for (int i = N + 1; i <= M; ++i)
    {
        fin >> arrive >> leave;

        auto el = p.begin();

        if (el->first <= arrive)
        {
            int index_cpy = el->second.index;

            p.erase(el);
            p[leave] = { index_cpy, arrive };

            fout << index_cpy << '\n';
        }
        else
            fout << "-1\n";

        //for (auto el : p)
            //cout << el.first << ' ' << el.second.index << '\n';
    }

    for (auto el : p)
    {
        if (el.first <= T)
            pq.push({ el.second.index, -1 });
        else
            pq.push({ el.second.index, el.second.arrived });
    }

    while (!pq.empty())
    {
        fout << pq.top().second << ' ';
        pq.pop();
    }
}

int main()
{
    read();

    return 0;
}
