// https://dmoj.ca/problem/dpd

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll N, W;
ll v[100];
ll w[100];

ll recurse(ll newW, ll idx) {
    if (idx == 0) {
        if (w[idx] <= newW) {
            return v[idx];
        } else {
            return 0;
        }
    }
    if (w[idx] > newW) {
        return recurse(newW, idx - 1);
    }
    return max(recurse(newW, idx - 1), v[idx] + recurse(newW - w[idx], idx - 1));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    cout << recurse(W, N-1) << "\n";
}