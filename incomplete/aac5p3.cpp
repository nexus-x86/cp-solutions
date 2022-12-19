// https://dmoj.ca/problem/aac5p3
// https://github.com/nexus-x86/cp-solutions
// Thursday November 17 2022

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int mx = 1e9+5;
int N, K;
vector<vector<pair<int,int>>> adjList;
int skillLevels[mx];
int visited[mx];
pair<int,int> range[mx];

void dfs(int v, pair<int,int> bounds) {
    visited[v] = 1;
    int left = bounds.first;
    int right = bounds.second;
    if (left > right || (left == 0 && right == 0)) {
        return;
    }
    pair<int,int> lastRange = bounds;

    int n = adjList[v].size();
    for (int i = 0; i < n; i++) {
        int v2 = adjList[v][i].first;
        int wt = adjList[v][i].second;

        if (visited[v2]) {
            continue;
        }

        int nextVert = -1;
        int nextWt = -1;

        if (i + 1 != n) {
            if (!visited[adjList[v][i+1].second]) {
                nextWt = adjList[v][i+1].second;
                nextVert = adjList[v][i+1].first;
            } else if (i + 3 <= n) {
                nextWt = adjList[v][i+2].second;
                nextVert = adjList[v][i+2].first;                
            }
        }
        
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adjList[a].push_back(make_pair(b,d));
        ajdList[b].push_back(make_pair(a,d));
    }

    for (int i = 1; i <= K; i++) {
        cin >> skillLevels[i];
    }

}