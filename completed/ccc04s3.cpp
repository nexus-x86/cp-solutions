// https://dmoj.ca/problem/ccc04s3
// https://github.com/nexus-x86/cp-solutions
// Thursday August 31 2023

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string graph[11][11];
int ans[11][11];
int visited[11][11];

int dfs(int y, int x) {

    if (isdigit(graph[y][x][0])) {
        ans[y][x] = stoi(graph[y][x]);
        return ans[y][x];
    } else if (ans[y][x] != -1) {
        return ans[y][x];
    }
    if (visited[y][x] == 1) {
        return -1;
    }
    visited[y][x] = 1;
    int iter = 0;
    int len = graph[y][x].size();
    int myAns = 0;
    while (iter < len) {
        // row is iter
        // column is iter + 1
        int row = graph[y][x][iter] - 'A';
        int column = graph[y][x][iter+1] - '1';
        //cout << "(" << column << ", " << row << ")" << graph[y][x][iter] << " " << graph[y][x][iter+1] << "\n" << flush;
        int next = dfs(row, column);
        if (next == -1) {
            ans[y][x] = -1;
            return -1;
        }
        myAns += next;
        iter+=3;
    }
    ans[y][x] = myAns;
    return myAns;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(ans, -1, sizeof(ans));
    memset(visited,-1,sizeof(visited));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            int ans = dfs(i, j);
            if (ans == -1) {
                graph[i][j] = '*';
            } else {
                graph[i][j] = to_string(ans);
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}