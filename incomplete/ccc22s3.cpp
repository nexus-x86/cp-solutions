// https://dmoj.ca/problem/ccc22s3
// https://github.com/nexus-x86/cp-solutions
// Thursday December 22 2022

#include <iostream>

using namespace std;

typedef long long ll;

ll N, M, K;

const ll mx = 1e6+5;
ll ans[mx];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K; // n notes, m is max pitch, k is requested good samples
    // to maximise the amount of good samples in a sequence
    // we do: 1 2 3 4 5 6
    // to minimize we do
    // samenumber samenumber samenumber samenumber samenumber samenumber
    // the strat is to maximize by going up, we hit a poll where
    // we stop and then we just repeat. the number we repeat and the poll we
    // select must be carefully chosen

    // let t be the maximum number of good samples the next number can create
    // if t < min(M, index), we pick the number at index index - t. this is 
    // discovered through working it out on paper

    // we can use k as a counter for how many samples left we need to create
    // when the next number will turn k negative, this is when we know
    // we switch over to samenumber samenumber samenumber
    
    K -= 1;
    ans[0] = 1;
    ll index = 1;
    for (ll i = 1; i < N; i++) {
        ll remaining = N - i;
        if (remaining == K) { // once this becomes true, it will remain true
            ans[index] = ans[index-1];
            index++;
            K--;
        } else if (remaining > K) {
            break;
        } else {
            // we have K left
            //cout << K << "\n";
            //cout << i << "\n";
            //cout << newNum << " " << newNum << "\n";

            ll maxForCurrent = min(K - remaining + 1, M);
            if (maxForCurrent > i && i < M) {
                ans[index] = i + 1;
                index++;
                K -= (i + 1);
            } else {
                ans[index] = ans[i - maxForCurrent];
                index++;
                K -= maxForCurrent;
            }
        }
    }
    //cout << K << "\n";
    //cout << K << " " << index << "\n";
    if (K == 0 && index == N) {
        for (ll i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
        
    }
    
}