// https://dmoj.ca/problem/ppwindsor18p4
// https://github.com/nexus-x86/cp-solutions
// Sunday December 18 2022

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int emptyHousePositions[N];
    int badHousePositions[M];

    for (int i = 0; i < N; i++)
    {
        cin >> emptyHousePositions[i];
        // cout << emptyHousePositions[i] << " ";
    }

    cout << "\n";
    for (int j = 0; j < M; j++)
    {
        cin >> badHousePositions[j];
        // cout << badHousePositions[j] << " ";
    }

    int bestDistance = -1;
    int bestHouse = -1;
    for (int i = 0; i < N; i++)
    {

        int closestHouse = -1;
        int dist = 1000000500;
        for (int j = 0; j < M; j++)
        {
            // find the closest house
            // cout << "Houses " << i << " and " << j << " have distance: " << abs(badHousePositions[j] - emptyHousePositions[i]) << "\n";
            if (abs(badHousePositions[j] - emptyHousePositions[i]) < dist)
            {
                dist = abs(badHousePositions[j] - emptyHousePositions[i]);
                closestHouse = emptyHousePositions[i];
            }
        }

        if (dist > bestDistance && closestHouse != -1)
        {
            bestDistance = dist;
            bestHouse = closestHouse;
        }
        else if (dist == bestDistance)
        {
            bestHouse = min(bestHouse, closestHouse);
        }
    }

    cout << bestHouse << "\n";

    return 0;
}