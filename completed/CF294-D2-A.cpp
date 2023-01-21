// https://codeforces.com/contest/294/problem/A
// https://github.com/nexus-x86/cp-solutions
// Wednesday January 18 2023

#include <iostream>

using namespace std;

int birds[105];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> birds[i];
    }
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        //birds[x];
        int goingUp = y - 1;
        int goingDown = birds[x] - y;
        if (x - 1 >= 0) {
            birds[x-1] += goingUp;
        }
        if (x + 1 <= n) {
            birds[x+1] += goingDown;
        }
        birds[x] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cout << birds[i] << "\n";
    }
}   