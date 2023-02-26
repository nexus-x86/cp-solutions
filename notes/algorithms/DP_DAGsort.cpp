#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int mx = 1e6;
int nodes, edges;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> nodes >> edges;

    vector<int> adjList[mx];
    int in_degree[mx];
    deque<int> dq;
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        in_degree[b - 1]++;
    }
    for (int i = 0; i < nodes; i++) {
        if (in_degree[i] == 0) {
            dq.push_back(i);
        }
    }
    vector<int> ans;
    while (!dq.empty()) {
        int curr = dq.front();
        dq.pop_front();

        for (auto v : adjList[curr]) {
            in_degree[v]--;
            if (in_degree[v] > 0) {
                continue;
            }
            dq.push_back(v);
            ans.push_back(v);
        }
    }

    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}