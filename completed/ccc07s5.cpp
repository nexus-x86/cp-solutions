// https://dmoj.ca/problem/ccc07s5
// https://github.com/nexus-x86/cp-solutions
// Wednesday January 18 2023

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll mx = 3e4+500;

ll val[mx];
ll dp[501][mx];

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, w;
        cin >> n >> k >> w;
        // n -> bowling pins
        // k -> bowling balls
        // w -> width
        memset(val, 0, sizeof(val));
        memset(dp, 0, sizeof(dp));

        for (ll i = 1; i <= n; i++) {
            cin >> val[i];
            val[i] += val[i-1]; // psa
        }

        // dp[i][j] is the maximum score of a player with i balls and j pins

        for (ll i = 1; i <= k; i++) {
            for (ll j = 1; j <= n; j++) {
                if (j < w) {
                    dp[i][j] = val[j];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - w] + val[j] - val[j - w]);
                }
            }
        }
        cout << dp[k][n] << "\n";
    }
    // 2D Dynamic programming array
}