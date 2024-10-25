#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> CalculateAccelerationSequence(int targetHeight, int timeLimit);

int main()
{
    int numberOfFlights = 4;
    int minimumHeights[] = { 125, 7, 40, 161 };
    int timeLimits[] = { 50, 50, 50, 50 };

    for (int i = 0; i < numberOfFlights; i++)
    {
        cout << "Flight " << (i + 1) << ":" << endl;
        vector<int> accelerations = CalculateAccelerationSequence(minimumHeights[i], timeLimits[i]);
        for (int acc : accelerations)
        {
            cout << acc << " ";
        }
        cout << endl << endl;
    }

    return 0;
}

vector<int> CalculateAccelerationSequence(int targetHeight, int timeLimit)
{
    vector<int> accelerations;
    int currentHeight = 0;
    int velocity = 0;
    const int maxAcceleration = 20;

    // Ascend until the target height is reached or exceeded
    while (currentHeight < targetHeight && accelerations.size() < timeLimit)
    {
        int acceleration = min(maxAcceleration, (targetHeight - currentHeight) / 2);
        accelerations.push_back(acceleration);
        velocity += acceleration - 10;  // Considering gravity effect
        currentHeight += velocity;
    }

    // Begin descent, reducing velocity to reach a soft landing (velocity of 0 or -1 at height 0)
    while (currentHeight > 0 && accelerations.size() < timeLimit)
    {
        int descentAcceleration = -min(maxAcceleration, currentHeight / 2);
        if (velocity <= -10) descentAcceleration += 19;  // Apply upward acceleration for controlled descent
        else descentAcceleration = 0;  // Free fall when close to ground

        accelerations.push_back(descentAcceleration);
        velocity += descentAcceleration - 10;  // Gravity effect
        currentHeight += velocity;

        if (currentHeight < 0)
        {
            currentHeight = 0;
            velocity = max(velocity, -1);  // Ensuring soft landing
        }
    }

    // Final check for soft landing
    if (velocity < -1)
    {
        accelerations.push_back(1);  // Apply gentle upward acceleration for a soft landing
        velocity += 1 - 10;  // Gravity effect
    }

    return accelerations;
}
