// https://dmoj.ca/problem/ccc20s2
// https://github.com/nexus-x86/cp-solutions
// Wednesday January 25 2023

#include <iostream>

using namespace std;

const int mx = 1000 + 2000;
int grid[mx+1][mx+1] = {0};
int visited[mx+1][mx+1] = {0};
int M, N;

int dfs(int x, int y) {
    if (x > N || y > M) {
        return 0;
    }
    if (visited[y][x] == 1) {
        return 0;
    }
    visited[y][x] = 1;
    if (y == M && x == N) {
        return 1;
    }

    int num = grid[y][x];
    for (int i = 1; i*i <= num; i++) {
        if (num % i == 0) {
            int a1 = i;
            int a2 = num / i;
            if (dfs(a1,a2)) {
                return 1;
            }
            if (dfs(a2,a1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    if (dfs(1,1) == 1) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

}