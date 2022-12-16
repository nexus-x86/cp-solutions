// http://www.usaco.org/index.php?page=viewproblem2&cpid=917
// https://github.com/nexus-x86/cp-solutions
// Sunday December 4 2022

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("traffic");
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    string highway[100];
    int low[100];
    int high[100];

    for (int i = 0; i < N; i++) {
        cin >> highway[i] >> low[i] >> high[i];
    }

    int lowerAns = -10000;
    int higherAns = 10000;

    for (int i = N - 1; i >= 0; i--) {
        if (highway[i] == "none") {
            if (low[i] > lowerAns) {
                lowerAns = low[i];
            }
            if (high[i] < higherAns) {
                higherAns = high[i];
            }
        } else if (highway[i] == "off") {
            lowerAns += low[i];
            higherAns += high[i];
        } else if (highway[i] == "on") {
            higherAns -= low[i];
            lowerAns -= high[i];
        }
    }

    cout << max(lowerAns,0) << " " << higherAns << "\n";
    
    lowerAns = -10000;
    higherAns = 10000;
    for (int i = 0; i < N; i++) {
        if (highway[i] == "none") {
            if (low[i] > lowerAns) {
                lowerAns = low[i];
            }
            if (high[i] < higherAns) {
                higherAns = high[i];
            }
        } else if (highway[i] == "on") {
            lowerAns += low[i];
            higherAns += high[i];
        } else if (highway[i] == "off") {
            higherAns -= low[i];
            lowerAns -= high[i];
        }
    }
    cout << max(lowerAns,0) << " " << higherAns << "\n";

    return 0;
}