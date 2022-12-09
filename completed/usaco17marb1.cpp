// http://www.usaco.org/index.php?page=viewproblem2&cpid=735
// https://github.com/nexus-x86/cp-solutions
// Sunday December 4 2022

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("lostcow");
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    // farmer john at x
    // bessie at y
    y -= x;
    x -= x;
    int goal = 1;

    int distance = 0;
    while (x != y) {
        distance++;
        if (goal > 0) {
            x++;
        } else if (goal < 0) {
            x--;
        }
        if (x == goal) {
            goal *= -2;
        }
        //cout << "Farmer john at " << x << "\n";
    }
    cout << distance << "\n";
    return 0;
}