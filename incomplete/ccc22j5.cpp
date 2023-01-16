// https://dmoj.ca/problem/https://dmoj.ca/problem/ccc22j5
// https://github.com/nexus-x86/cp-solutions
// Sunday January 8 2023

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int N,T;
int row[105];
int col[105];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 105; i++) {
        row[i] = 0;
        col[i] = 0;
    }
    cin >> N >> T;
   
    for (int i = 0; i < T; i++) {
        cin >> row[i] >> col[i];
    }
    row[T] = 0;
    col[T] = 0;

    int ans = 0;
    for (int r : row) {
        for (int c : col) {
            int size = min(N - r, N - c);
            for (int k = 0; k < T + 1; k++) {
                if (r < row[k] && c < col[k]) {
                    size = min(size, max(row[k] - r, col[k] - c) - 1);
                }
            }
            ans = max(ans, size);
        }
    }
    cout << ans << "\n";
}