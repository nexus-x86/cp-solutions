// https://dmoj.ca/problem/dpd

#include <iostream>

using namespace std;

typedef long long ll;
ll N, W;
ll v[100];
ll w[100];
ll dp[100][100001];

ll recurseMemo(ll newW, ll idx) { // Same as brute force except using memoization
    // Information already computed is stored to an array so it isn't
    // computed again.
    // Since this uses memoization, this solution is considered "Top-down"
    if (dp[idx][newW] != -1) {
        return dp[idx][newW];
    }
    if (idx == 0) {
        if (w[idx] <= newW) {
            dp[idx][newW] = v[idx];
            return v[idx];
        } else {
            dp[idx][newW] = 0;
            return 0;
        }
    }
    if (w[idx] > newW) {
        dp[idx][newW] = recurseMemo(newW, idx - 1);
        return dp[idx][newW];
    }
    dp[idx][newW] = max(recurseMemo(newW, idx - 1), v[idx] + recurseMemo(newW - w[idx], idx - 1));
    return dp[idx][newW];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100001; j++) {
            dp[i][j] = -1;
        }
    }
    cout << recurseMemo(W, N-1);
}