// https://dmoj.ca/problem/mec16p3
// https://github.com/nexus-x86/cp-solutions
// Tuesday January 10 2023
#include <algorithm>
#include <iostream>

using namespace std;

const int mx = 1e6;

int wt[mx];
int val[mx];
int dp[mx];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, T;
    cin >> N >> T;
    
    int a = 0;

    for (int i = 0; i < N; i++) {
        int L;
        cin >> L;
        int rollingTime = 0;
        int rollingEXP = 0;
        for (int j = 0; j < L; j++) {
            int t, z;
            cin >> t >> z;
            rollingTime += t;
            rollingEXP += z;
            wt[a] = rollingTime;
            val[a] = rollingEXP;
            a++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = T; j >= 0; j--) {
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
        }
    }
    cout << dp[N] << "\n";
}