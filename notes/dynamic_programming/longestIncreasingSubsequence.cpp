#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int seq[N];
    int LIS[N];
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
        LIS[i] = 1;
    }

    // Let dp[i] be the longest increasing subsequence that 

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    //cout << LIS[N - 1] << "\n";
    cout << *max_element(begin(LIS), end(LIS)) << "\n";
}