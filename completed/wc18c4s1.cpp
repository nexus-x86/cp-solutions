// https://dmoj.ca/problem/wc18c4s1
// https://github.com/nexus-x86/cp-solutions
// Thursday October 20 2022

/*
Editorial:
The idea is to use a disjoint set union, and only union planet connections
if they are owned by the same race.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    string R;
    cin >> R;
    /*
    N planets
    M space routes
    K friends
    */
    vector<int> parent(N + 1);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        if (R.at(A-1) == R.at(B-1)) {
            int vertex1 = A;
            int vertex2 = B;

            while (vertex1 != parent[vertex1]) {
                vertex1 = parent[vertex1];
            }
            while (vertex2 != parent[vertex2]) {
                vertex2 = parent[vertex2];
            }
            if (vertex1 != vertex2) {
                parent[vertex2] = vertex1;
            }
        }
    }
    int counter = 0;
    for (int i = 0; i < K; i++) {
        int X, Y;
        cin >> X >> Y;
        while (X != parent[X]) {
            X = parent[X];
        }
        while (Y != parent[Y]) {
            Y = parent[Y];
        }
        if (X == Y) {
            counter++;
        }
    }
    cout << counter << "\n";
}