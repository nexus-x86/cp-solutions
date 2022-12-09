// http://www.usaco.org/index.php?page=viewproblem2&cpid=891
// https://github.com/nexus-x86/cp-solutions
// Saturday December 3 2022

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("shell");
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int counters[3] = {0};
    int swaps[3] = {1,2,3};
    int currMax = 0;
    for (int i = 0; i < N; i++) {
        int a,b,g;
        cin >> a >> b >> g;
        for (int j = 0; j < 3; j++) {
            if (swaps[j] == a) {
                swaps[j] = b;
            } else if (swaps[j] == b) {
                swaps[j] = a;
            }
            if (swaps[j] == g) {
                counters[j]++;
                if (counters[j] > currMax) {
                    currMax = counters[j];
                }
            }
        }
    }
    cout << currMax << "\n";
    return 0;
}