// http://www.usaco.org/index.php?page=viewproblem2&cpid=1061
// https://github.com/nexus-x86/cp-solutions
// Saturday December 17 2022

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int mx = 1e5+5;
unordered_map<int, vector<int>> adjList;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<int> PhoRests;

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        PhoRests.push_back(a);
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    

    return 0;
}