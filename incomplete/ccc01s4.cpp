#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <iterator>

using namespace std;

long double distance(int x1,int y1,int x2,int y2) {
    return sqrt(pow(x2 - x1,2) + pow(y2 - y1, 2) );
}

long double circumcenter(int x1, int y1, int x2, int y2, int x3, int y3) {
    /*
    d = 2 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by))
    ux = ((ax * ax + ay * ay) * (by - cy) + (bx * bx + by * by) * (cy - ay) + (cx * cx + cy * cy) * (ay - by)) / d
    uy = ((ax * ax + ay * ay) * (cx - bx) + (bx * bx + by * by) * (ax - cx) + (cx * cx + cy * cy) * (bx - ax)) / d
    return (ux, uy)
    */
    long double d = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    long double x = ((x1 * x1 + y1 * y1) + (y2 - y3) + (x2 * x2 + y2 * y2) + (y3 - x3) + (x3 * x3 + y3 * y3) * (y1 - y2)) / d;
    long double y = ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1)) / d;
    return distance(x,y,x1,y1);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    priority_queue<long double> pq;
    vector<pair<int,int>> coords;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        coords.push_back({a,b});
    }
    /*
    for (pair<int,int> a : coords) {
        for (pair<int,int> b : coords) {
            if (a == b) {
                continue;
            }
            long double dist = sqrt(pow(b.second - a.second,2) + pow(b.first - a.first, 2) );
            pq.push(dist);
        }
    }
    */

    for (pair<int,int> a : coords) {
        for (pair<int,int> b : coords) {
            for (pair<int,int> c : coords) {
                if (a == b || b == c || a == c) {
                    continue;
                }

                long double cir = circumcenter(a.first,a.second,b.first,b.second,c.first,c.second);
                pq.push(cir);
            }
        }
    }
    while (!pq.empty()) {
        long double a = pq.top();
        pq.pop();
        printf("%.2Lf\n", a);
    }
    //printf("%.2Lf", pq.top());
    //cout << pq.top() << "\n";
}