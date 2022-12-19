// https://dmoj.ca/problem/cco14p2
// https://github.com/nexus-x86/cp-solutions
// Thursday December 1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

const int mx = 1e5;
int N, M, A, B, Q;
unordered_map<int, vector<tuple<int,int,int>>> adjList;

int main() {
    cin >> N >> M >> A >> B;
    for (int i = 0; i < M; i++) {
        int X, Y, L, C;
        cin >> X >> Y >> L >> C;
        adjList[X].push_back(make_tuple(Y, L, C));
        adjList[Y].push_back(make_tuple(X, L, C));
    }

    // every road between A and B

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int myDistanceValue;
        cin >> myDistanceValue;

    }

    // King Gruff hates the foxen living in city A and City B
    // He want's to make it as inconvenient or impossible to travel from
    // City A to city B
    // King Gruff will shut down all roads shorter than or equal todistance D
    // which belong on at least 1 path from City A to City B
    // We are given Q different distance values
    // Output the cost of shutting down all these roads for each Q value
}