// https://dmoj.ca/problem/rgpc18p3
// https://github.com/nexus-x86/cp-solutions
// Sunday October 30 2022 

#include <iostream>
#include <vector>
using namespace std;

const int mx = 1e6+10;

int main() {
    int N,T;
    cin >> N >> T;

    vector<int> d(N+1,0);

    for (int i = 0; i < T; i++) { // difference array
        int a,b,c;
        cin >> a >> b >> c;
        d[a] += c;
        d[b+1] -= c;
    }
    int limit;
    cin >> limit;
    for (int i = 1; i <= N; i++) { // converting it to normal array
        d[i] += d[i-1];
    }
    int leftPointer = 1;
    int rightPointer = 1; // array is 1-indexed
    int s = 0;
    int maxCups = 0;

    while (leftPointer <= N) {
        bool m = false;
        while (rightPointer <= N-1) {
            if (s + d[rightPointer +1] <= limit ) {
                s += d[rightPointer+1];
                m = true;
                rightPointer++;
            } else {
                break;
            }
        }
        if (m) {
            maxCups = max(maxCups, rightPointer - leftPointer +1);
            s -= d[leftPointer];
        }
        leftPointer++;

    }
    cout << maxCups << "\n";
    // 6 7 7 8 4 1
    // 6 1 0 1 -4 -3

}