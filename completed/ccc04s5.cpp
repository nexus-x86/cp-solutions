// https://dmoj.ca/problem/ccc04s5
// https://github.com/nexus-x86/cp-solutions
// Tuesday February 7 2023

#include <iostream>
#include <cstring>

using namespace std;

int rows, cols;
int grid[103][103];
int dp[103][103];


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    while (cin >> rows >> cols && (rows || cols)) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                char c;
                cin >> c;
                if (c == '.') {
                    grid[i][j] = 0;
                } else if (c == '*') {
                    grid[i][j] = -1;
                } else {
                    grid[i][j] = c - '0';
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        dp[rows-1][0] = grid[rows-1][0];
        for (int i = rows - 2; i >= 0; i--) {
            if (grid[i][0] >= 0) {
                dp[i][0] = dp[i+1][0] + grid[i][0];
            } else {
                break;
            }
        }

        

        for (int c = 1; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                if (dp[r][c-1] >= 0) {
                    int t = dp[r][c-1];
                    for (int k = r; k < rows; k++) {
                        if (grid[k][c] >= 0) {
                            t += grid[k][c];
                            if (t > dp[k][c]) {
                                dp[k][c] = t;
                            }
                        } else {
                            break;
                        }
                    }
                }
            }
            for (int r = rows - 1; r >= 0; r--) {
                if (dp[r][c-1] >= 0) {
                    int t = dp[r][c-1];
                    for (int k = r; k >= 0; k--) {
                        if (grid[k][c] >= 0) {
                            t += grid[k][c];
                            if (t > dp[k][c]) {
                                dp[k][c] = t;
                            }
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        cout << dp[rows-1][cols-1] << "\n";
    }
}