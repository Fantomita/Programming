#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int file = 1; file <= 5; ++file)
    {
        string inputFile = "level1_" + to_string(file) + ".in";
        string outputFile = "level1_" + to_string(file) + ".out";

        ifstream fin(inputFile);
        ofstream fout(outputFile);

        int N;
        fin >> N;  // Number of flights
        for (int i = 0; i < N; ++i) 
        {
            int height = 0;
            int velocity;

            // Process each flight's velocities
            while (fin >> velocity) 
            {
                height += velocity;
                // Ensure height is non-negative
                if (height < 0) height = 0;
                // Check for the end of current line (end of current flight)
                if (fin.peek() == '\n' || fin.eof()) break;
            }

            fout << height << endl;  // Output final height for this flight
        }
    }
   
    
    return 0;
}