// https://dmoj.ca/problem/dpg
// https://github.com/nexus-x86/cp-solutions
// Thursday February 9 2023

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;

const int mx = 1e5+500;

vector<int> adjList[mx];
int longestPath[mx];

int dfs(int v) {
    if (longestPath[v] != -1) {
        return longestPath[v];
    }

    int belowLength = 0;

    for (int child : adjList[v]) {
        belowLength = max(belowLength, dfs(child));
    }

    longestPath[v] = 1 + belowLength;

    return longestPath[v];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(longestPath, -1, sizeof(longestPath));

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
    }

    int maxNum = 0;

    for (int i = 1; i <= N; i++) {
        maxNum = max(maxNum, dfs(i));
    }
    maxNum -= 1;
    cout << maxNum << "\n";
}