// https://dmoj.ca/problem/ccc16s3
// https://github.com/nexus-x86/cp-solutions
// Saturday December 17 2022

#include <iostream>
#include <vector>
using namespace std;
const int mx = 1e5+5;
vector<int> adjList[mx];
int pho[mx], childIsPho[mx];
int n, m, randomPho;
int remainingNodes = 0;
int diameter = 0;
int furthestNode = 0;

void dfs(int node, int prev) {
    childIsPho[node] = pho[node];
    for (int children : adjList[node]) {
        if (children == prev) {
            continue;
        }
        dfs(children,node);
        childIsPho[node] |= childIsPho[children];
    }
    if (childIsPho[node]) {
        remainingNodes++;
    }
}
void GIVEMETHEDIAMETERPLEASE(int node, int prev, int dist) {
    if (dist > diameter){ 
        diameter = dist;
        furthestNode = node;
    }
    for (int children : adjList[node]) {
        if (children == prev || !childIsPho[children]) {
            continue;
        }
        GIVEMETHEDIAMETERPLEASE(children, node, dist + 1);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> randomPho;
        pho[randomPho] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        int a,b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    dfs(randomPho,-1);
    GIVEMETHEDIAMETERPLEASE(randomPho,-1,0);
    GIVEMETHEDIAMETERPLEASE(furthestNode,-1,0);
    cout << diameter + (remainingNodes - (diameter + 1)) * 2 << "\n";
}