#include <bits/stdc++.h>
using namespace std;

void parseInput(const string& line, vector<int>& disk)
{
    int index = 1, type = 1;
    for (const auto& c : line)
    {
        if (type == 0)
        {
            for (int i = 0; i < (c - '0'); ++i)
            {
                disk.push_back(0);
            }
        }
        else
        {
            for (int i = 0; i < (c - '0'); ++i)
            {
                disk.push_back(index);
            }
            index++;
        }

        type = (type + 1) % 2;
    }
}

void rearrangeDisk(vector<int>& disk)
{
    int left = 0, right = disk.size() - 1;
    while (left < right)
    {
        if (disk[left])
        {
            left++;
            continue;
        }
        if (disk[right] == 0)
        {
            right--;
            continue;
        }

        swap(disk[left], disk[right]);
        left++;
        right--;
    }
}

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    string line;
    vector<int> disk;
    getline(cin, line);

    parseInput(line, disk);
    rearrangeDisk(disk);

    long long ans = 0;
    for (int i = 0; i < disk.size(); ++i)
    {
        if (disk[i] == 0)
            break;

        ans += i * (disk[i] - 1);
    }

    cout << ans;

    return 0;
}