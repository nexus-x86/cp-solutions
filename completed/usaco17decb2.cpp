// http://www.usaco.org/index.php?page=viewproblem2&cpid=760
// https://github.com/nexus-x86/cp-solutions
// Sunday December 4 2022

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("shuffle");
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int a[N+1]; // 0 1 2 3 4 5
    int cows[N+1];
    for (int i = 1; i <= N; i++) {
        int b;
        cin >> b;
        // a[i] = b;
        // cow at i goes to b
        // therefore to reverse it
        // cow at b goes to i
        a[b] = i;
    }

    for (int i = 1; i <= N; i++) {
        cin >> cows[i];
    }
    for (int i = 1; i <= 3; i++) {
        int newCows[N + 1];

        for (int j = 1; j <= N; j++) {
            int idx = a[j];
            newCows[idx] = cows[j];
        }
        copy(newCows, newCows + N + 1, cows);
    }
    for (int i = 1; i <= N; i++) {
        cout << cows[i] << "\n";
    }
    return 0;
}