// https://dmoj.ca/problem/ccc01s3
// https://github.com/nexus-x86/cp-solutions
// Wednesday December 28 2022

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
// Represent as adjacency list
// vector<int> adjList[50];

int adjMatrix[50][50];

int visited[50][50];
vector<string> output;
vector<string> inputs;
string in;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    // Remove every road and check if this removes the paths, if yes
    // add to list and output it
    while (cin >> in) {
        if (in == "**") {
            break;
        }
        inputs.push_back(in);
        adjMatrix[in[0] - 'A' + 1][in[1] - 'A' + 1] = 1;
        adjMatrix[in[1] - 'A' + 1][in[0] - 'A' + 1] = 1;
    }

    int counter = 0;
    for (string road : inputs) {
        memset(visited, 0, sizeof(visited));

        visited[road[0] - 'A' + 1][road[1] - 'A' + 1] = 1;
        visited[road[1] - 'A' + 1][road[0] - 'A' + 1] = 1;

        queue<int> myQueue;
        myQueue.push(1);
        bool flag = true;
        while (!myQueue.empty()) {
            int front = myQueue.front();
            myQueue.pop();
            if (front == 2) {
                flag = false;
                break;
            }
            for (int i = 1; i <= 26; i++) {
                if (!visited[front][i] && adjMatrix[front][i]) {
                    visited[front][i] = 1;
                    visited[i][front] = 1;
                    myQueue.push(i);
                }
            }
        }
        if (flag){ 
            counter += 1;
            cout << road << "\n";
        }
    }
    cout << "There are " << counter << " disconnecting roads.\n";
}