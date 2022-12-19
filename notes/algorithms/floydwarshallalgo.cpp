#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 0x3f3f3f3f;
int Vertices = 6;
int AM[vertices][Vertices];


void addEdge(int u, int v) {
    AM[u][v] = 1;
    AM[v][u] = 1;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); 

    for (int k = 0; k < Vertices; k++) {
        for (int i = 0; i < Vertices; i++) {
            for (int j = 0; j < Vertices; j++) {
                AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
            }
        }
    }
}