#include <bits/stdc++.h>
using namespace std;

void parseInput(const string& line, vector<int>& disk, unordered_map<int, int>& IDs)
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
            IDs[index] = (c - '0');
            index++;
        }

        type = (type + 1) % 2;
    }
}

void rearrangeDisk(vector<int>& disk, const unordered_map<int, int>& IDs)
{
    for (int blockID = IDs.size(); blockID >= 1; --blockID)
    {
        int blockStart = -1, blockEnd = -1, blockSize = 0;
        for (int i = 0; i < disk.size(); ++i)
        {
            if (disk[i] == blockID)
            {
                if (blockStart == -1)
                {
                    blockStart = i;
                }
                blockEnd = i;
                blockSize++;
            }
        }

        if (blockStart == -1)
        {
            continue;
        }

        int targetStart = -1;
        int freeSpace = 0;
        for (int i = 0; i < disk.size() && i < blockStart; ++i)
        {
            if (disk[i] == 0)
            {
                freeSpace++;
            }
            else
            {
                freeSpace = 0;
            }

            if (freeSpace >= blockSize)
            {
                targetStart = i - freeSpace + 1;
                break;
            }
        }

        if (targetStart != -1)
        {
            for (int i = blockStart; i <= blockEnd; ++i)
            {
                disk[i] = 0;
            }

            for (int i = 0; i < blockSize; ++i)
            {
                disk[targetStart + i] = blockID;
            }
        }
    }
}

int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");

    string line;
    vector<int> disk;
    unordered_map<int, int> IDs;
    getline(cin, line);

    parseInput(line, disk, IDs);
    rearrangeDisk(disk, IDs);

    // for (auto it : disk)
    // {
    //     if (it == 0)
    //         cout << '.';
    //     else
    //         cout << (it - 1);
    // }
    // cout << '\n';

    long long ans = 0;
    for (int i = 0; i < disk.size(); ++i)
    {
        ans += i * (disk[i] - 1);
    }

    cout << ans;

    return 0;
}
