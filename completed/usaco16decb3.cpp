// http://www.usaco.org/index.php?page=viewproblem2&cpid=665
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
    setIO("cowsignal");
    cin.sync_with_stdio(0);
    cin.tie(0);

    int M, N, K;
    cin >> M >> N >> K;

    // M by N grid of letters that needs to be amplified in every direction
    // by K

    for (int i = 0; i < M; i++) {
        // first expand horizontally, than repeat it vertically by K
        string a;
        cin >> a;
        string b = "";
        for (char&c : a) {
            for (int j = 0; j < K; j++) {
                b += c;
            }
        }
        for (int j = 0; j < K; j++) {
            cout << b << "\n";
        }
    }

    return 0;
}