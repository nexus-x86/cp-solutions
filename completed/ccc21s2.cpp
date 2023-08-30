// https://dmoj.ca/problem/ccc21s2
// https://github.com/nexus-x86/cp-solutions
// Wednesday January 11 2023
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int M, N, K;
const int mx = 5e6+5;
int freqR[mx];
int freqC[mx];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(freqR, 0, sizeof(freqR));
    memset(freqC, 0, sizeof(freqC));

    cin >> M >> N >> K;

    while (K--) {
        char a;
        int b;
        cin >> a >> b;
        if (a == 'R') {
            freqR[b]++;
        } else {
            freqC[b]++;
        }
    }

    int gold = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if ((freqR[i] + freqC[j]) % 2 == 1) {
                // an even number of operations would ensure that this is black
                // if it is odd than there is an odd number of operations,
                // therefore this must be gold, so we increment
                gold++;
            }
        }
    }
    cout << gold << "\n";
}