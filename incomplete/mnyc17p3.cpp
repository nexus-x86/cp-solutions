#include <iostream>
#include <string>

using namespace std;

const int mx = 1e6+50;
const int p = 27;
const int mod = 1e9 + 7;

int pow[mx];
int h[mx];

string a, b;

typedef long long ll;

void init() {
    pow[0] = 1;
    for (int i = 1; i < a.size(); i++) {
        pow[i] = ((ll) pow[i-1] * p) % mod;
    }
}

void computeRollingHash() {
    h[0] = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i != 0) {
            h[i] = h[i - 1];
        }
        h[i] = (h[i] + ((ll) a[i] * pow[i]) % mod) % mod;
    }
}

int computeHash() {
    int output = 0;
    for (int i = 0; i < b.size(); i++) {
        output = (output + ((ll)b[i] * pow[i]) % mod) % mod;
    }
}

ll fastExp(ll a, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}

int hash_fast(int L, int R) {
    if (L ==0 ) {
        return h[R];
    }
    int ans = 0;
    ans = ((h[R] - h[L-1]) % mod + mod) % mod;
    ans = ((ll) ans * fastExp(pow[L], mod - 2)) % mod;
    return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    init();
    computeRollingHash();
    
}