/*
Disjoint set data structure
AKA union_Set find (UFDS) 
Merge-find

This data structure stores a collection of disjoint set

Each set has a representative
union_Set find UFDS
merge find

3 operations
Make_Set ( Given a new element, make a set with just this element ) Runs in O(1) time
union_Set ( Join 2 sets together ) Runs in O(1)
Find ( find the representative of a element) Runs in O(1)


We find elements by going up the representatives, but this is inefficient 

Optimizations
1: Path Compression
Goes up and goes back down to assign each element to the root
2: Rank compression
Consider if we have a straight line in a disjoint set data structure therefore we use rank compression
rank compression compresses the lines to be as short as possible. assigns nodes heights
*/

#include <iostream>
#include <vector>

using namespace std;

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

int main() {
    initialize(10); // 0 -> 9
    for (int i : p) {
        cout << i << " ";
    }
    cout << "\n";
    union_Set(1,2);
    union_Set(3,4);
    for (int i : p) {
        cout << i << " ";
    }
    cout << "\n";
    union_Set(1,3);
    for (int i : p) {
        cout << i << " ";
    }
    cout << "\n";
    cout << isSameSet(0,1) << "\n";
    cout << isSameSet(8,9) << "\n";
    cout << isSameSet(1,2) << "\n";
    cout << isSameSet(1,4) << "\n";
    cout << isSameSet(2,3) << "\n";
    cout << isSameSet(1,3) << "\n";
    cout << isSameSet(3,9) << "\n";
    cout << "FindSets" << "\n";
    cout << findSet(5) << "\n";
    cout << p[5] << "\n";
    cout << findSet(4) << "\n";
    cout << p[4] << "\n";
    cout << findSet(3) << "\n";
    cout << p[3] << "\n";
    cout << findSet(2) << "\n";
    cout << p[2] << "\n";
    cout << findSet(1) << "\n";
    cout << p[1] << "\n";
    cout << findSet(0) << "\n";
    cout << p[0] << "\n";
}