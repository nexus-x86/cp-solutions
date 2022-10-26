// https://dmoj.ca/problem/wc18c4s1
// https://github.com/nexus-x86/cp-solutions
// Thursday October 20 2022

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> parent, height;

void initialize(int N) {
    parent.assign(N,0);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    height.assign(N,0);
}

int findSet(int i) {
    if (parent[i] == i) {
        return i;
    }
    parent[i] = findSet(parent[i]);
    return parent[i];
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j) {
    if (isSameSet(i,j)) {
        return;
    }
    int x = findSet(i);
    int y = findSet(j);
    if (height[x] > height[y]) {
        swap(x,y);
    }
    parent[x] = y;
    if (height[x] == height[y]) {
        height[y]++;
    }
}

int N, M, K;
string R;

int main() {
    cin >> N >> M >> K >> R;
    int counter = 0;
    initialize(N+1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (R.at(a-1) == R.at(b-1)){
            unionSet(a,b);
        }
    }
    for (int j = 0; j < K; j++) {
        int x,y;
        cin >> x >> y;
        if (findSet(x) == findSet(y)) {
            counter++;
        }
    }
    cout << counter << "\n";
}