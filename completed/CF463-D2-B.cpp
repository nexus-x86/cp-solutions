// https://codeforces.com/contest/463/problem/B
// https://github.com/nexus-x86/cp-solutions
// Sunday January 22 2023

#include <iostream>
#include <queue>

using namespace std;

int main() {    
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int h[n+ 1];

    h[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    int ans = 0;
    int energy = 0;
    for (int i = 1; i <= n; i++) {
        energy += h[i-1]-h[i];
        if (energy < 0) {
            ans += -1*energy;
            energy = 0;
        }
    }
    cout << ans << "\n";
}