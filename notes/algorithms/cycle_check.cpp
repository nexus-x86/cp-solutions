#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

const int V = 4;

//vector<vector<int>> adjList[V];
unordered_map<int, vector<int>> adjList;
int visited[V] = {0};
int OnStack[V] = {0};

bool hasCycle = false;
    
//le epic recursion function. using dfs
//in a non directed graph. a cycle is considered to be non-trivial if its length is at least 3
//same idea as the directed graph version except we also need to keep track of which vertex we came from

void cycleCheck(int u, int previous) {
    visited[u] = 1;
    OnStack[u] = 1;
    cout << "Going to vertex " << u << " from vertex " << previous << "\n";
    for (auto i : adjList[u]) {
        if (hasCycle) {
            cout <<"Cycle found at  " << i << "\n";
            return;
        } else if (!visited[i]) {
            cycleCheck(i, u);
        } else if (OnStack[i] && previous != i) {
            hasCycle = true;
            return;
        }
    }
    OnStack[u] = false;
}

void addEdge(int a, int b) {
    adjList[a].push_back(b);
    adjList[b].push_back(a);
}



int main() {
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,2);
    addEdge(2,3);   
    /*adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[2].push_back(0);
    adjList[2].push_back(3);
    adjList[3].push_back(3);
    adjList[1].push_back(2);*/

    //vector<int> recursiOnStack;
    cycleCheck(0, 0);
}