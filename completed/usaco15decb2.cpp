// http://www.usaco.org/index.php?page=viewproblem2&cpid=568
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
    setIO("speeding");
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int currIndex = 0;
    int theRoad[100];
    for (int i = 0; i < N; i++) {
        int length, speedlimit;
        cin >> length >> speedlimit;
        int a;
        for (a = currIndex; a < (currIndex+length); a++) {
            theRoad[a] = speedlimit;
        }
        currIndex = a;
    }
    int maximum = 0;
    currIndex = 0;
    for (int i = 0; i < M; i++) {
        int length, mySpeed;
        cin >> length >> mySpeed;
        int a;
        for (a = currIndex; a < (currIndex+length); a++) {
            if (mySpeed - theRoad[a] > maximum) {
                maximum = mySpeed - theRoad[a];
            } 
        }
        currIndex = a;
    }
    cout << maximum << "\n";
    return 0;
}