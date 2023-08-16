#include <iostream>

using namespace std;

const int mx = 16 * 4;
int st[mx];
int A[mx];
int N;

void build() {
    for (int k = N - 1; k > 0; k--) {
        st[k] = min(st[k << 1], st[(k << 1) + 1]);
    }
}

void update(int i, int val) {
    st[N + 1] = val;
    for (int k = ((N + 1) >> 1); k >= 1; k >>= 1) {
        st[k] = min(st[k << 1], st[(k << 1) + 1]);
    }
}
int query(int L, int R) {
    int res = 2e6;
    L += N;
    R += N;
    while (L < R) {
        if (L & 1) {
            res = min(res, st[L++]);
        }
        if (R & 1) {
            res = min(res, st[--R]);
        }
        L >>= 1;
        R >>=1;
    }
    return res;
}
int rmq() {
    return 0;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> st[i];
    }

    build();

    for (int i = 0; i <= 20; i++) {
        cout << st[i] << " ";
    }
    cout << "\n";

}