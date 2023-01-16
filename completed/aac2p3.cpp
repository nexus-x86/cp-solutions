// https://dmoj.ca/problem/aac2p3
// https://github.com/nexus-x86/cp-solutions
// Friday November 18

#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int mx = 1505;

ll N, M;

ll psa[mx][mx];
deque<pair<int,int>> dq;
bool visited[mx][mx];
bool compute(int size) {
    if (psa[size][size] != 0) {
        return false;
    }
    if (psa[N][M] - psa[N - size][M] - psa[N][M - size] + psa[N - size][M - size] != 0) {
        return false;
    }

    memset(visited, false, sizeof(visited));

    dq.clear();
    dq.push_back({size, size});
    visited[size][size] = true;

    while (!dq.empty()) {
        //auto x = dq.back();
        auto x = dq.front();
        int r = x.first;
        int c = x.second;
        dq.pop_back();
        
        if (r < N && !visited[r + 1][c]) {
            if (psa[r + 1][c] - psa[r + 1 - size][c] - psa[r + 1][c - size] + psa[r + 1 - size][c - size] == 0) {
                dq.push_back({r + 1, c});
            }
            visited[r + 1][c] = true;
            if (r + 1 == N && c == M) {
                break;
            }
        }
        if (c < M && !visited[r][c + 1]) {
            if (psa[r][c + 1] - psa[r - size][c + 1] - psa[r][c + 1 - size] + psa[r - size][c + 1 - size] == 0) {
                dq.push_back({r, c + 1});
            }
            visited[r][c + 1] = true;
            if (r == N && c + 1 == M) {
                break;
            }
        }
        if (size < r && !visited[r - 1][c]) {
            if (psa[r - 1][c] - psa[r - 1 - size][c] - psa[r - 1][c - size] + psa[r - 1 - size][c - size] == 0) {
                dq.push_back({r - 1, c});
            }
            visited[r - 1][c] = true;
        }
        if (size < c && !visited[r][c - 1]) {
            if (psa[r][c - 1] - psa[r - size][c - 1] - psa[r][c - 1 - size] + psa[r - size][c - 1 - size] == 0) {
                dq.push_back({r, c - 1});
            }
            visited[r][c - 1] = true;
        }
        
    }
    return visited[N][M];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char c;
            cin >> c;
            if (c == 'O') {
                psa[i][j] = 0;
            } else {
                psa[i][j] = 1;
            }
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }

    int size = 0;
    for (size = min(M,N); size > 0; size--) {
        if (compute(size)) {
            break;
        }
    }
    cout << size << "\n";
}