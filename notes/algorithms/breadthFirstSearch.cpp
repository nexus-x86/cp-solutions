#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int mx = 1e5;
vector<vector<int>> adjList(mx);
bool visited[mx];
queue<int> myQueue;

void addEdge(int v1, int v2) {
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
}

void recursiveBFS(queue<int> myEpicQueue) {
    if (myEpicQueue.empty()) {
        return;
    }
    int x = myEpicQueue.front();
    myEpicQueue.pop();

    for (int i : adjList[x]) {
        if (!visited[i]) {
            visited[i] = true;
            cout << i << "\n";
            myEpicQueue.push(i);
        }
    }

    recursiveBFS(myEpicQueue);
}

int main() {
    visited[0] = true;
    myQueue.push(0);
    
    addEdge(0,1);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,5);
    addEdge(3,7);
    addEdge(2,7);
    addEdge(5,69);
    addEdge(69,420);

    while (!myQueue.empty()) {
        int x = myQueue.front();
        myQueue.pop();
        for (int i : adjList[x]) {
            if (!visited[i]) {
                visited[i] = true;
                cout << i << "\n";
                myQueue.push(i);
            }
        }
    }

    memset(visited,false,mx); // reset the list to demo the recursive dfs
    queue<int> myOtherQueue;
    myOtherQueue.push(0);
    recursiveBFS(myOtherQueue);
}