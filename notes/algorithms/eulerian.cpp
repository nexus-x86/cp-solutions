#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int nodes, edges;
const int mx = 1e5;
vector<int> adjList[mx];

vector<int> heirholzer(int s) {
    vector<int> ans;
    int idx[nodes];
    memset(idx, 0, sizeof(idx));
    vector<int> stack;
    stack.push_back(s);

    while (!stack.empty()) {
        int u = stack.back();
        if (idx[u] < (int)adjList[u].size()) {
            stack.push_back(adjList[u][idx[u]]);
            idx[u]++;
        } else {
            ans.push_back(u);
            stack.pop_back();
        }
    }
    return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // the first time we have a cycle, put the cycle in the stack,
    // every time you pop a node out of the stack, check if there is a node that 
    // hasnt been used

    vector<int> amm = heirholzer(1);
    for (int b : amm) {
        cout << b << " ";
    }
    cout << "\n";
}