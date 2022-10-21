// https://dmoj.ca/problem/wc18c4s1
// https://github.com/nexus-x86/cp-solutions
// Thursday October 20 2022

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> p, height, setSize;

int numSets;

string R;
char safetyColor = ' ';


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
    int N, M, K;
    cin >> N >> M >> K >> R;
    initialize(N+1);
    // 6 4 P P
    // 2 3 Z Z
    // 1 5 
    /*
    N planets
    M space routes
    K friends
    */
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        // route between planet A and B
        union_Set(A,B);
    }
    int counter = 0;
    for (int i = 0; i < K; i++) {
        int X, Y;
        cin >> X >> Y;
        // ith friend on planet X, wants to go to planet Y
        // check if X and Y is owned by the same race
        // and if there is a space route
        safetyColor = R[X-1];
        if (R[X-1] == R[Y-1] && isSameSet(X,Y)) {
            counter++;
        }
    }
    cout << counter << "\n";
}