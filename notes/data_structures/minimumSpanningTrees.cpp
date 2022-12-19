#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <algorithm>

using namespace std;

const int mx = 1e5;
vector<vector<pair<int,int>>> adjList(mx); // endpoint, weight
vector<tuple<int,int,int>> edgeList; // weight, start, end
bool connected[mx];
priority_queue<pair<int,int>> pq; // weight, endpoint

void addEdge(int v1, int v2, int wt) {
    adjList[v1].push_back(make_pair(v2,wt));
    adjList[v2].push_back(make_pair(v1,wt));
    edgeList.push_back(make_tuple(wt,v1,v2));
}

int main() {
    /*
    A tree represents a hierarchical tree structure.
    Each node can be connected to any amount of children but each node
    can only have exactly 1 parent
    Except the root.
    Basically, no cycles, no loops

    A spanning tree is a subgraph of an undirected connected graph
    that includes all the vertices of the original graph

    When there is only 1 connected component in our graph, the spanning forest
    is the same as the spanning tree, but when there are multiple connected components
    each component will have a spanning tree and all those trees
    constitute a forest
    more info: https://stackoverflow.com/questions/43252588/spanning-tree-vs-spanning-forest    

    Minimum spanning tree (MST), a spanning tree that has the minimum weight
    */
    
    // using the https://en.wikipedia.org/wiki/Minimum_spanning_tree 
    // spanning tree example for testing purposes

    addEdge(1,2,9);
    addEdge(2,3,6);
    addEdge(3,4,9);
    addEdge(4,5,4);
    addEdge(5,6,4);
    addEdge(6,1,18);
    addEdge(2,8,3);
    addEdge(1,8,9);
    addEdge(3,8,4);
    addEdge(8,7,9);
    addEdge(8,9,2);
    addEdge(1,7,8);
    addEdge(7,9,8);
    addEdge(3,9,2);
    addEdge(9,4,9);
    addEdge(4,7,7);
    addEdge(7,6,10);
    addEdge(7,10,9);
    addEdge(10,4,5);
    addEdge(10,5,1);
    addEdge(10,6,3);

    addEdge(11,12,1); // second connected component of the graph
    addEdge(12,13,2);
    int vertices = 13;
    /*
    Prim's Algorithm (aka Jarnik's Algorithm)
    An O(E log V) greedy algorithm to find the minimum spanning tree of a connected graph

    Start with any vertex and place it in connected,
    Pick the edge with minimum weight that is connected to a connected vertex
    and an unconnected vertex. 
    each time add the other end of the new edge to connected
    stop whenn all edges are visited
    */

    int cost = 0;
    connected[1] = true;
    for (pair<int,int> i : adjList[1]) {
        pq.push({-i.second,-i.first});
    }
    while (!pq.empty()) {
        pair<int,int> x = pq.top();
        pq.pop();
        if (!connected[-x.second]) {
            cost += -x.first;
            connected[-x.second] = true;
            for (pair<int,int> i : adjList[-x.second]) {
                if (!connected[-i.first]) {
                    pq.push({-i.second,-i.first});
                }
            }
        }
    }
    cout << cost << "\n"; // expected output is 38

    /*
    Kruskal's Algorithm 
    An O(E log V) greedy algorithm to find the minimum spanning forest
    
    sort all edges in ascending order based on weight
    pick the edge with the minimum weight that joins 2 disjoint sets
    use a UFDS (union find data structure)
    stop when all edges are considered
    */
    
    // UFDS declarations
    vector<int> parent(vertices+1);
    for (int i = 1; i <= vertices; i++) {
        parent[i] = i;
    }
    sort(edgeList.begin(),edgeList.end());
    int cost2 = 0;
    for (tuple<int,int,int> x : edgeList) {
        int v1 = get<1>(x);
        while (v1 != parent[v1]) {
            v1 = parent[v1];
        }
        int v2 = get<2>(x);
        while (v2 != parent[v2]) {
            v2 = parent[v2];
        }
        if (v1 != v2) {
            parent[v2] = v1;
            cost2 += get<0>(x);
        }
    }
    cout << cost2 << "\n"; // outputs 41, which is correct.
    // there is a 11,12,13 component and an everything else component
}