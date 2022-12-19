#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int mx = 1e5;
vector<vector<int>> adjList(mx);
bool visited[mx];
stack<int> myStack;

void addEdge(int v1, int v2) {
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
}

void recursiveDFS(int v) {
    if (visited[v] == true) {
        return;
    }
    visited[v] = true;
    cout << v << "\n";
    for (int i : adjList[v]) {
        recursiveDFS(i);
    }
}

int main() {
    visited[0] = true;
    myStack.push(0);

    addEdge(0,1);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,5);
    addEdge(3,7);
    addEdge(2,7);
    addEdge(5,69);
    addEdge(69,420);

    while (!myStack.empty()) {
        int x = myStack.top();
        myStack.pop();
        for (int i : adjList[x]) {
            if (!visited[i]) {
                visited[i] = true;
                myStack.push(i);
                cout << i << "\n";
            }
        }
    }

    memset(visited,false,mx); // reset the list to demo the recursive dfs
    recursiveDFS(0);
}