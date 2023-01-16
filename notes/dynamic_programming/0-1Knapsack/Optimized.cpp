// https://dmoj.ca/problem/dpd

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

// This is the optimized bottom up solution.

ll N, W;
ll dp[100001];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = W; j >= 0; j--) {
            if (j >= w) {
                dp[j] = max(dp[j], dp[j - w] + v);
            }
        }
    }
    cout << dp[W] << "\n";
}