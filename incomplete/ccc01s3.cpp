// https://dmoj.ca/problem/ccc01s3
// https://github.com/nexus-x86/cp-solutions
// Wednesday December 28 2022

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

unordered_map<char, vector<char>> adjList;

//vector<bool> visited;
unordered_map<char, bool> visited;
unordered_map<char, int> tin, low;
int timer = 0;

set<char> specificNodes;

set<string> articulationPoints;

int n; 

void dfs(char v, char  p) {
    visited[v] = true;
    timer += 1;
    tin[v] = timer;
    low[v] = timer;
    for (char to : adjList[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v] && p != ' ') {
                string myStr = "";
                myStr += v;
                myStr += p;
                sort(myStr.begin(), myStr.end());
                articulationPoints.insert(myStr);
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    //visited.assign(n, false);
    for (char a : specificNodes) {
        tin[a] = -1;
        low[a] = -1;
    }
    //tin.assign(n, -1);
    //low.assign(n, -1);
    for (char mychar : specificNodes) {
        if (!visited[mychar])
            dfs(mychar, ' ');
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string in;
    while (cin >> in) {
        if (in == "**") {
            break;
        }
        adjList[in[0]].push_back(in[1]);
        specificNodes.insert(in[0]);
        specificNodes.insert(in[1]);
    }


    find_bridges();

    for (string a : articulationPoints) {
        cout << a << "\n";
    }
    cout << "There are " << articulationPoints.size() << " disconnecting roads.\n";
}