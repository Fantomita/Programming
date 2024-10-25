#include <bits/stdc++.h>
using namespace std;

//ifstream fin("input.txt");
//ofstream fout("output.txt");

int height, width;
int mat[1005][1005];
int treeX, treeY;
const int MAX_DEPTH = 10000; // You can adjust this value
int depth;
int startX, startY;


bool inmat(int x, int y, int maxHeight, int maxWidth)
{
    return x > 0 && x <= maxHeight && y > 0 && y <= maxWidth; 
}

bool hitWall(char dir, int x, int y, int height, int width)
{
    if(dir == 'W' && mat[x - 1][y] != 0 && mat[x][y - 1] == 0 && mat[x][y + 1] == 0)
        return true;
    if(dir == 'S' && mat[x + 1][y] != 0 && mat[x][y - 1] == 0 && mat[x][y + 1] == 0)
        return true;
    if(dir == 'A' && mat[x][y - 1] != 0 && mat[x - 1][y] == 0 && mat[x + 1][y] == 0)
        return true;
    if(dir == 'D' && mat[x][y + 1] != 0 && mat[x - 1][y] == 0 && mat[x + 1][y] == 0)
        return true;
    return false;
} 

bool isNeighbour(int x, int y)
{
    if(abs(startX - x) == 1 && startY - y == 0)
        return true;
    if(abs(startY - y) == 1 && startX - x == 0)
        return true;
    return false;
    
}

int numNeighbours(int x, int y)
{
    return !mat[x - 1][y] + !mat[x + 1][y] + !mat[x][y - 1] + !mat[x][y + 1];
}

vector<tuple<int,int,int>> leastNeighbours(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3)
{
    vector<tuple<int,int,int>> ass;
    
    int num, num1, num2, num3;

    num = numNeighbours(x, y);
    num1 = numNeighbours(x1, y1);
    num2 = numNeighbours(x2, y2);
    num3 = numNeighbours(x3, y3);
    
    ass.push_back(make_tuple(num, x, y));
    ass.push_back(make_tuple(num1, x1, y1));
    ass.push_back(make_tuple(num2, x2, y2));
    ass.push_back(make_tuple(num3, x3, y3));

    return ass;
}

char getDir(pair<int, int> coords, int x, int y)
{
    char dir;
    if(coords.first == x - 1) dir = 'S';
    if(coords.first == x + 1) dir = 'W';
    if(coords.second == y - 1) dir = 'D';
    if(coords.second == y + 1) dir = 'A';

    return dir;
}

void bectreching(int x, int y, int height, int width, string path, bool& found, ofstream &fout)
{
    if (depth > MAX_DEPTH) return; // Stop if depth exceeds the threshold

    if (inmat(x, y, height, width) && mat[x][y] == 0 && !found && !(depth > MAX_DEPTH))
    {
        if(hitWall(path[(int)path.size() - 1], x, y, height, width)) return;

        mat[x][y] = 1;

        if (path.size() == height * width - 3)
        {
            int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
            char dict[] = {'W', 'D', 'S', 'A'};
            int newX, newY;

            for (int k = 0; k < 4; ++k)
            {
                newX = x + dx[k];
                newY = y + dy[k];

                if (inmat(newX, newY, height, width) && mat[newX][newY] == 0 && isNeighbour(newX, newY))
                {
                    path += dict[k];
                    fout << path << '\n';
                    found = true;
                    break;
                }
            }
        }
        
        vector<tuple<int, int, int>> ln = leastNeighbours(x + 1, y, x - 1, y, x, y + 1, x, y - 1);
        
        sort(ln.begin(), ln.end());
        for(auto i : ln)
        {
            int x1, y1, num;
            tie(num, x1, y1) = i;
            if(num == 0) continue;
            char dir = getDir(make_pair(x, y), x1, y1);
            if (inmat(x1, y1, height, width) && mat[x1][y1] == 0 && !found)
            {
                depth++;
                bectreching(x1, y1, height, width, path + dir, found, fout);
            }
            if(found) return;    
        }
        mat[x][y] = 0;
        depth--;
    }
    if (found) return;
}

int main()
{
    for (int file = 1; file <= 5; ++file)
    {
        string inputFile = "level7_" + to_string(file) + ".in";
        string outputFile = "level7_" + to_string(file) + ".out";

        ifstream fin(inputFile);
        ofstream fout(outputFile);

        int n;
        fin >> n;

        for (int i = 1; i <= n; i++)
        {
            int width, height;
            fin >> width >> height;

            memset(mat, 0, sizeof(mat));

            for (int j = 0; j <= height + 1; j++)
            {
                mat[j][0] = -1;
                mat[j][width + 1] = -1;
            }
            for (int j = 0; j <= width + 1; j++)
            {
                mat[0][j] = -1;
                mat[height + 1][j] = -1;
            }

            for (int j = 1; j <= height; j++)
            {
            for (int k = 1; k <= width; k++)
                {
                    char ch;
                    fin >> ch;

                    if (ch == 'X')
                    {
                        treeX = j;
                        treeY = k;

                        mat[j][k] = -1;
                    }
                }
            }

            bool found = false;

            // Try backtracking from all four corners

            for (startX = 1; startX <= height; ++startX)
            {
                if (found) break;

                depth = 0;
                startY = 1;
                bectreching(startX, startY, height, width, "", found, fout);

                if (found) break;

                depth = 0;
                startY = width;
                bectreching(startX, startY, height, width, "", found, fout);
            }

            for (startY = 1; startY <= width; ++startY)
            {
                if (found) break;

                depth = 0;
                startX = 1;
                bectreching(startX, startY, height, width, "", found, fout);

                if (found) break;

                depth = 0;
                startX = height;
                bectreching(startX, startY, height, width, "", found, fout);
            }

/*             depth = 0;
            bectreching(1, 1, height, width, "", found, fout);
            startX = 1, startY = 1;
            depth = 0;
            if(!found) bectreching(1, width, height, width, "", found, fout);
            startX = 1, startY = width;
            depth = 0;
            if(!found) bectreching(height, 1, height, width, "", found, fout);
            startX = height, startY = 1;
            depth = 0;
            if(!found) bectreching(height, width, height, width, "", found, fout);
            startX = height, startY = width; */

            // If no solution was found
            if(!found)
            {
                fout << "No solution found\n";
            }

        }
    }
    

    return 0;
}
