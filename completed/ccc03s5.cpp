// https://dmoj.ca/problem/ccc03s5
// https://github.com/nexus-x86/cp-solutions
// Friday November 25

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int mx = 10005;
struct Edge{int w, n;};

//vector<vector<pair<int,int>>> adjList(mx+5, vector<pair<int,int>>(0) );
vector<Edge> adjList[mx];
int dist[mx];
bool connected[mx];

bool myComparator(int a,int b) {  
    return dist[a] < dist[b];
}  

int main() {
    int c, r, d;
    cin >> c >> r >> d;
    // cities from 1 -> c

    for (int i = 0; i < r; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        // road runs between x and y with a maximum weight capacity of w

        adjList[x].push_back({w,y});
        adjList[y].push_back({w,x});
    }

    priority_queue<int, vector<int>, function<bool(int,int)>> pq(myComparator);
    pq.push(1);
    dist[1] = 0x3f3f3f3f;
    connected[1] = true;
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        connected[x] = false;

        for (Edge p : adjList[x]) {
            int m = min(dist[x], p.w);
            if (m > dist[p.n]) {
                dist[p.n] = m;
                if (!connected[p.n]) {
                    pq.push(p.n);
                    connected[p.n] = true;
                }
            }   
        }
    }

    int m = 0x3f3f3f3f;
    for (int i = 0; i < d; i++) {
        int dest;
        cin >> dest;
        m = min(m,dist[dest]);
    }
    cout << m << "\n";
    return 0;
}