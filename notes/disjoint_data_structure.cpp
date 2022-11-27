#include <iostream>
#include <vector>

using namespace std;

const int VertexAmount = 10;
vector<int> parent(VertexAmount+1,0);
vector<int> rankUnion(VertexAmount+1,0);

void make_set(int v) {
    parent[v] = v;
    rankUnion[v] = 0;
}

int find_set(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]); // Path compression optimization
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rankUnion[a] < rankUnion[b]) {
            swap(a,b);
        }
        parent[b] = a;
        if (rankUnion[a] == rankUnion[b]) {
            rankUnion[a]++;
        }
    }
}

int main() {


    for (int i = 1; i <= VertexAmount; i ++) {
        // MAKING A SET
        parent[i] = i; // Each vertex is it's own parent.
        // END 
    }

    // FINDING A SET
    int vertexIAmLookingFor = 2;
    while (vertexIAmLookingFor != parent[vertexIAmLookingFor]) {
        vertexIAmLookingFor = parent[vertexIAmLookingFor];
    }

    // END

    // UNIONING A SET
    int vertex1 = 1;
    int vertex2 = 10;

    while (vertex1 != parent[vertex1]) {
        vertex1 = parent[vertex1];
    }
    while (vertex2 != parent[vertex2]) {
        vertex2 = parent[vertex2];
    }
    if (vertex1 != vertex2) {
        parent[vertex2] = vertex1;
    }
    // END

}