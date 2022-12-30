// https://dmoj.ca/problem/ccc09s4
// https://github.com/nexus-x86/cp-solutions
// Tuesday November 29

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;

const int mx = 5e6+1000;
unordered_map<int, vector<pair<int,int>>> adjList;

int maxNum = 2147483647;
bool visited[mx];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> dijkstra;
    // priority queue keeps all the cities sorted by the cost of a pencil
    int N, T;
    cin >> N >> T;
    for (int i = 0; i < T; i++) {
        int x, y, C;
        cin >> x >> y >> C;
        adjList[x].push_back(make_pair(y,C));
        adjList[y].push_back(make_pair(x,C));
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int z, P;
        cin >> z >> P;    
        dijkstra.push(make_pair(P,z));
    }
    int D;
    cin >> D; 
    while (!dijkstra.empty()) {
        pair<int,int> myPair = dijkstra.top();
        dijkstra.pop();
        int v = myPair.second;
        int wt = myPair.first;
        if (v == D) {
            cout << wt << "\n";
            return 0;
        }
        if (visited[v]) {
            continue;
        }
        visited[v] = 1;
        for (int i = 0; i < adjList[v].size(); i++) {
            dijkstra.push(make_pair(wt+adjList[v][i].second,adjList[v][i].first));
        }
    }
    
}