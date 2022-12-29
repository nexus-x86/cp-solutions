// https://dmoj.ca/problem/ccc00s5
// https://github.com/nexus-x86/cp-solutions
// Wednesday December 28 2022

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<double, double>> sheeps; // essential
    for (int i = 0; i < N; i++)
    {
        double x, y;
        cin >> x >> y;
        x *= 1000;
        y *= 1000;
        sheeps.push_back({x, y});
    }

    set<pair<double, double>> visited;
    set<pair<double, double>> possibleBestSheep;

    for (double i = 0; i <= 1000 * 1000; i += 0.01 * 1000)
    {
        double bestDistance = 1e5 * 1000;
        set<pair<double, double>> tempSheep;
        for (pair<double, double> sheep : sheeps)
        {
            double distance = sqrt(pow((sheep.first - i), 2) + pow((sheep.second), 2));
            if (distance < bestDistance)
            {

                tempSheep.clear();
                // possibleBestSheep.push_back(sheep);
                tempSheep.insert(sheep);
                visited.insert(sheep);
                bestDistance = distance;
            }
            else if (distance == bestDistance)
            {
                // possibleBestSheep.push_back(sheep);
                tempSheep.insert(sheep);
                visited.insert(sheep);
            }
        }
        for (pair<double, double> sheep : tempSheep)
        {
            possibleBestSheep.insert(sheep);
        }
    }
    for (pair<double, double> sheep : possibleBestSheep)
    {
        printf("The sheep at (%.2f, %.2f) might be eaten.\n", sheep.first / 1000, sheep.second / 1000);
    }
}