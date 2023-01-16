// https://dmoj.ca/problem/dpd

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

// Bottom up looks at smaller sub-problems and then solves the larger sub problems
// Essentially building the end-solution up.

// In this solution for the knapsack problem, the following formula is used
// Let dp[n][w] be the largest possible value using only the first n items with total weight
// at most w. The recursive relation formula is 
// dp[n][w] = max(dp[n-1][w], dp[n-1][w-wi] + vi)

ll N, W;
ll dp[101][100001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = 0; j <= W; j++) {
            if (j >= w) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][W];

}