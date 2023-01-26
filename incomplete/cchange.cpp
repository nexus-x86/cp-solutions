#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[10001];
int counter[10001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    for (int i = 0; i <= 10000; i++) {
        dp[i] = 1e6;
        counter[i] = 0;
    }
    counter[0] = 1;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = a; j <= x; j++) {
            counter[j] += counter[j - a];

            //dp[j] = min(dp[j], dp[j - a] + 1);
        }
    }
    cout << counter[x] << "\n";
    //cout << dp[x] << "\n";

    // 4 4 4 4 4 4
    // 2 2 4 4 4 4 4
    // 2 2 2 2 4 4 4 4
    // 2 2 2 2 2 2 4 4 4
    // 2 2 2 2 2 2 2 2 4 4
    // 2 2 2 2 2 2 2 2 2 2 4 
    // 2 2 2 2 2 2 2 2 2 2 2 2 
}