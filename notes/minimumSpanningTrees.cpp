#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

const  int vertices = 6;

priority_queue<int> myFavouritePQ;
vector<int> visited (vertices,0);
//vector<pair<int,int>> adjList[vertices];
unordered_map<int, vector<pair<int,int>>> adjList[vertices];

vector<int> p, height, setSize;

int numSets;

void initialize(int N)
{
    p.assign(N, 0);
    for (int i = 0; i < N; ++i)
        p[i] = i;
    height.assign(N, 0);  // optional speedup
    setSize.assign(N, 1); // optional feature
    numSets = N;          // optional feature
}
int findSet(int i)
{
    if (p[i] == i)
        return i;
    p[i] = findSet(p[i]); // Path Compression
    return p[i];
}
bool isSameSet(int i, int j)
{
    return findSet(i) == findSet(j);
}

int numDisjointSets() // optional
{
    return numSets;
}
int sizeOfSet(int i) // optional
{
    return setSize[findSet(i)];
}

void union_Set(int i, int j)
{
    if (isSameSet(i, j)) // i and j are in same set
        return;
    int x = findSet(i); // find rep items
    int y = findSet(j); // find rep items
    if (height[x] > height[y])
        swap(x, y); // union_Set by rank
    p[x] = y;       // set x under y
    if (height[x] == height[y])
        ++height[y];          // optional speedup
    setSize[y] += setSize[x]; // combine set sizes at y
    --numSets;                // a union_Set reduces numSets
}

// adjlist[vertice].pushback(make_pair(1,2)) where 1 is the next vertice 
// and 2 is the weight
int minimumCost = 0;
void PrimsAlgorithm(int curr) {
    /*
    prim's algorithm (jarnik's algorithm)
    An O(E Log V) greedy algorithm that finds the minimum spanning tree of a connected graph.
    1. let visited be the set of visited vertices
    2. Start with any vertex and place it in visited. 
    3. Repeatedly pick the edge with minimum weight that is connected to a visited vertex
     and an unvisited  vertex. Each time add the other end of the new edge to visited. The list of possible
     edges is saved in a priority queue. In the case of a tie, pick the vertex with a larger label
    4. stop when all the vertices are in visited or when you run out of all the edges in your priority queue
    */

    visited[curr] = 1;
    int minimum = INT_MAX;
    int minimumEdge = 0;
    for (vector<pair<int,int>> ToandWeightPair : adjList[curr]) {
        int toVertice = ToandWeightPair.first;
        int weight = ToandWeightPair.second;
        if (visited[toVertice] == 1) {
            continue;
        }
        if (weight < minimum) {
            minimum = weight;
            minimumEdge = toVertice;
            visited[toVertice] = 1; // other end off the new edge is added to visited

        }
    }
    PrimsAlgorithm(minimumEdge);
}

void KruskalsAlgorithm(int curr) {
    /*
    1. sort all edges in non-decreasing order of their weight
    pick the smallest edge. check if it forms a cycle with the spanning tree formed so far
    2. if a cycle is not formed, include this edge. otherwise discard it. use a disjoint set union to do this.
    we can use union find algorithm to do this easily.
    3. repeat step #2 until there are v-1 edges in the spanning tree
    */
   sort(adjList.first,adjList.second);

   

}

void addEdge(int fromVert, int toVert, int weightOfEdge) {
    adjList[fromVert].push_back({toVert,weightOfEdge});
    adjList[toVert].push_back({fromVert,weightOfEdge});

}

using namespace std;
int main() {
    /*
    A1 
    B2
    C3
    D4
    E5
    F6
    */
    addEdge(1,2,1);
    addEdge(2,3,3);
    addEdge(2,4,2);
    addEdge(4,5,3);
    addEdge(5,6,2);
    PrimsAlgorithm(1); // start at vertex 1
    cout << minimumCost << "\n";
    /*
    a spanning tree is a subgraph of an undirected connected graph that is a tree which includes 
    all the vertices of the original graph
    a minimum spanning tree (MST): if a graph is edge-weighted then the minimum spanning tree is
    the spanning tree whose weight is the minimum
    */
    
    initialize(10);

    //declare a connected graph with edge weight

    addEdge(5,4,2);
    
}