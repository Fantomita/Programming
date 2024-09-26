/*
3 2
5 4
6 4
7 3

7 8 9
3 4 4 

10 12 13

--------------------

3 0
0 6
3 3
4 5

0 3 4
3 5 6

3 8 10

10 3 8

---------------------

2 2
10 8
16 6

12 18
6  8

18 26

26 18


orders = [
   6 = {16, 2},
   8 = {10, 1}
]

T(i) + 2 + 6 >= 16
T(i) >= 8
T(i) = 10
R: T(i) + D + PP = 10 + 2 + 6 = 18
*/

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>

#define NMAX 100005

using namespace std;

ifstream fin("ramen.in");
ofstream fout("ramen.out");

typedef pair<int, int> PII;

struct TIII { int position, time, index; };

int n, d;
vector<PII> client(NMAX);
//priority_queue<int, vector<int>, greater<int>> orderTime;
//priority_queue<PII, vector<PII>, greater<PII>> clientSeat;
//map<int, int> answer;
map<int, PII> orders;

void read()
{
    fin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        fin >> client[i].first >> client[i].second;

        /*orderTime.push(client[i].first);
        clientSeat.push({ client[i].second, i });*/

        orders[client[i].second] = { client[i].first, i };
    }
}

void solve()
{
    /*while (!orderTime.empty())
    {
        PII seat = clientSeat.top();
        int time = orderTime.top();

        clientSeat.pop();
        orderTime.pop();

        if ()

        answer[seat.second] = time + seat.first;
    }

    for (auto el : answer)
        fout << el.second << '\n';*/


}

int main()
{
    read();
    solve();

    return 0;
}
