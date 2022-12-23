// http://www.usaco.org/index.php?page=viewproblem2&cpid=1061
// https://github.com/nexus-x86/cp-solutions
// Saturday December 17 2022

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> pho(M, -1);
    for (int i = 0; i < M; i++)
    {
        cin >> pho[i];
    }
    vector<int> adjList[N - 1];
    int visited[N] = {0};
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    pho[0];

    return 0;
}