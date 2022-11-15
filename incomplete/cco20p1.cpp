// https://dmoj.ca/problem/cco20p1
// https://github.com/nexus-x86/cp-solutions
// Saturday November 5

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int,int> pointsOverlap;

int main() {
    int N;
    int L,R,Y;
    cin >> N >> L >> R >> Y;
    /*
        N friends
        we can hide from L to R inclusive
        Y is the y value we can hide on
    */
    for (int i = 0; i < N; i++) {
        int x,v,h;
        cin >> x >> v >> h;
        // 0 = (v/h)x+b
        // b = -(v/h)x

        double b = -(v/h) * x;

        // 0 = (-v/h)x+b2
        // b2 = -(-v/h)x

        double b2 = -(-v/h) * x;

        // y = (v/h)x + b
        
        // (Y - b)/(v/h)=x
        // (Y-b)/(-v/h)=x

        double x1val = (Y-b) / ((v/h));
        double x2val = (Y -b)/ ((-v/h));
        cout << x1val << " : " << x2val << "\n";
    }
    for (int i = L; i <= R; i++) {
        
    }
}