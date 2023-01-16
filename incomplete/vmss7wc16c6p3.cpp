// https://dmoj.ca/problem/vmss7wc16c6p3
// https://github.com/nexus-x86/cp-solutions
// Monday January 2 2023

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int mx = 1e6 + 5;
vector<int> adjList[mx];
int discoveryTime[mx];
int lowTime[mx];
set<int> articulationPoints;

void tarjansAlgorithm(int u, int p, int time)
{
    int children = 0;
    time++;
    lowTime[u] = time;
    discoveryTime[u] = time;
    for (int v : adjList[u])
    {
        if (v == p)
        {
            continue;
        }
        if (discoveryTime[v] == 0)
        {
            children++;
            tarjansAlgorithm(v, u, time);
            if (discoveryTime[u] <= lowTime[v] && p != -1)
            {
                articulationPoints.insert(u);
            }
            lowTime[u] = min(lowTime[u], lowTime[v]); // low[v]
        }
        else
        {
            lowTime[u] = min(lowTime[u], discoveryTime[v]);
        }
    }
    if (p == -1 && children > 1)
    {
        articulationPoints.insert(u);
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    // N nodes, M edges
    // bidirectional graph, every node connects to every other
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    tarjansAlgorithm(1, -1, 0);
    cout << articulationPoints.size() << "\n";
    for (int point : articulationPoints)
    {
        cout << point << "\n";
    }
}