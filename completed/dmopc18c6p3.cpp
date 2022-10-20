// https://dmoj.ca/problem/dmopc18c6p3
// https://github.com/nexus-x86/cp-solutions
// Thursday October 20 2022

#include <iostream>
#include <vector>
using namespace std;

using namespace std;
vector < int > p, height, setSize;
int numSets;
void initialize(int N) {
  p.assign(N, 0);
  for (int i = 0; i < N; ++i)
    p[i] = i;
  height.assign(N, 0); // optional speedup
  setSize.assign(N, 1); // optional feature
  numSets = N; // optional feature
}
int findSet(int i) {
  if (p[i] == i)
    return i;
  p[i] = findSet(p[i]); // Path Compression
  return p[i];
}
bool isSameSet(int i, int j) {
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
  p[x] = y; // set x under y
  if (height[x] == height[y])
    ++height[y]; // optional speedup
  setSize[y] += setSize[x]; // combine set sizes at y
  --numSets; // a union reduces numSets
}

int main() {
    int N, M;
    // N number of nodes
    // M number of edges
    cin >> N >> M;
    initialize(N * 2);
    // forest
    // there exists at most 1 path between each pair of nodes
    // restore path to a forest by removing only 1 edge
    for (int i = 0; i < M; i++) {
        int ai,bi;
        cin >> ai >> bi;
        unionSet(ai,bi);
    }
    int num = numDisjointSets() - N;
    if (M == N - num || M == N - num + 1) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}