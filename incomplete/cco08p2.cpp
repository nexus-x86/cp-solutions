// https://dmoj.ca/problem/cco08p2
// https://github.com/nexus-x86/cp-solutions
// Saturday October 15 2022

#include <iostream>
#include <unordered_map>
#include <string>
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

void unionSet(int i, int j) {
    if (isSameSet(i, j)) // i and j are in same set
        return;
    int x = findSet(i); // find rep items
    int y = findSet(j); // find rep items
    if (height[x] > height[y])
        swap(x, y); // Union by rank
    p[x] = y;       // set x under y
    if (height[x] == height[y])
        ++height[y];          // optional speedup
    setSize[y] += setSize[x]; // combine set sizes at y
    --numSets;                // a union reduces numSets
}

const int mx = 1e5+5;

unordered_map<string, int> streets;
int runningCounter = 1;

// all the parallel lines can be compressed to a single line
// carefully note that is a and b are parallel and c and d are parallel this does not mean d is parallel to a
// it can be assumed that if a line intersects 1 parallel line it intersects with all of them
int main() {
    initialize(mx);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        string a,b;
        cin >> a >> b;
        if (streets[a] == 0) {
            streets[a] = runningCounter;
            runningCounter++; 
        }
        if (streets[b] == 0) {
            streets[b] = runningCounter;
            runningCounter++; 
        }
        string c;
        cin >> c;
        
    }
}