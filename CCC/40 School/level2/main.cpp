#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int file = 1; file <= 5; ++file)
    {
        string inputFile = "level2_" + to_string(file) + ".in";
        string outputFile = "level2_" + to_string(file) + ".out";

        ifstream fin(inputFile);
        ofstream fout(outputFile);

        int N;
        fin >> N; 

        for (int i = 0; i < N; ++i) 
        {
            int height = 0; 
            int velocity = 0;  
            int acceleration;

            while (fin >> acceleration) 
            {
                    
                velocity += acceleration - 10;
                height += velocity;
                
                if (height < 0) height = 0;
                if (fin.peek() == '\n' || fin.eof()) break;
            }

            fout << height << endl;  
        }
    }
   
    
    return 0;
}