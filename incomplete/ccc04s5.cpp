// https://dmoj.ca/problem/ccc04s5
// https://github.com/nexus-x86/cp-solutions
// Tuesday February 7 2023

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 150;
char grid[mx][mx];
int dp[mx][mx];

int N, M;

int charToVal(char a) {
    if (a == '.') {
        return 0;
    }
    return a - '0';
}

int recurse(int i, int j, int previous) {
    if (i < 1 || i > N || j < 1 || j > M) {
        return 0; // maybe this needs to be -1
    }

    if (grid[i][j] == '*') {
        return 0;
    }

    if (i == N && j == 1) {
        return charToVal(grid[i][j]);
    }
    if (previous == 0) {
        dp[i][j] = max({recurse(i-1,j,-1), recurse(i+1,j,1), recurse(i,j-1,0)}) + charToVal(grid[i][j]);
    } else if (previous == -1) {
        dp[i][j] = max({recurse(i-1,j,-1), recurse(i,j-1,0)}) + charToVal(grid[i][j]);
    } else if (previous == 1) {
        dp[i][j] = max({recurse(i+1,j,1), recurse(i,j-1,0)}) + charToVal(grid[i][j]);
    }
    return dp[i][j];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }

        memset(dp, -1, sizeof(dp));

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> grid[i][j];
            }
        }

        // Mario cannot occupy a grid location he already ahs
        // Always moves to an adjacent cell
        // If mario moves up, he cannot move down until he moves right
        // If he moves down, he cannot move up until he moves right
        // peach is at the bottom right and mario is at the bottom left
        // find max numbers of coins mario can make

        cout << recurse(N,M,0) << "\n";
    }
}