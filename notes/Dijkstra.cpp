#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 0x3f3f3f3f;
vector<vector<pair<int, int>>> adj (9, vector<pair<int,int>>(0) );

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);

    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        u[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

void addEdge(int e1, int e2, int wt) {
    adj[e1].push_back({e2,wt});
    adj[e2].push_back({e1,wt});
}


int main() {
    // for each vertex v, adj[v] contains the list of edges going from this vertex, i.e. the list of pair<int,int>
    // where the first element in the pair is the vertex at the other end of the edge and the second element
    // is the weight

    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7); // 14

    // 1 2 3 4 5 6 7 8 9 10 11 14

    vector<int> distance;
    vector<int> previous;

    dijkstra(0,distance,previous); // calculates the minimum distance
    // from every note to 0
    
    for (int i = 0; i < 9; i++) {
        cout << i << " " << distance[i] << "\n";
    }
    
    vector<int> path = restore_path(0,8,previous);

    for (int a : path) {
        cout << a << "\n";
    }
}